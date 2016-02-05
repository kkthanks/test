<?php
require_once(LIB_PATH.DS.'db_connection.php');

class Comment extends DatabaseObject
{
    protected static $table_name = "bus_comments";
    // only included the db fields that are used in form submission
    protected static $db_fields = array('id', 'bus_route_id', 'body', 'user_name', 'created');

    public $id;
    public $bus_route_id;
    public $body;
    public $user_name;
    public $created;

    public static function make($bus_route_id, $body = "", $user_name = "unknown")
    {
        if (!empty($bus_route_id) && !empty($body) && !empty($user_name)) {
            $comment = new Comment();
            $comment->bus_route_id = (int)$bus_route_id;
            $comment->body = $body;
            $comment->user_name = $user_name;
            return $comment;
        } else {
            return false;
        }

    }

    public static function findCommentsOn($bus_route_id)
    {
        global $db;
        $statement  = "SELECT * FROM " . static::$table_name;
        $statement  = " WHERE bus_route_id=:bus_route_id";
        $statement .= " ORDER BY created ASC";

        $prepared = $db->prepare($statement);
        $prepared->bindValue(':bus_route_id', $bus_route_id, PDO::PARAM_INT);

        $prepared->execute();
        $rows = $prepared->fetchAll(PDO::FETCH_CLASS, static::class);
        return $rows;
    }
}
