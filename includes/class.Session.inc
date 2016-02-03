<?php

class Session
{

    // most of the functions should be done from an instantiated sessions class
    // no point leaving any info in session using static attributes or methods
    
    private $logged_in = false;
    public $user_id;

    public function __construct()
    {
        session_start();
        $this->check_login();
        if ($this->logged_in) {
            // actions to take when user is logged in
        } else {
            // actions to take when user is not logged in
        }
    }

    public function is_logged_in()
    {
        return $this->logged_in;
    }

    public function login($user)
    {
        //database should find user based on user name/password
        if ($user) {
            $this->user_id = $_SESSION['user_id'] = $user->id;
            $this->logged_in = true;
        }
    }

    public function logout()
    {
        unset($_SESSION['user_id']);
        unset($this->user_id);
        $this->logged_in = false;
    }

    private function check_login()
    {
        if (isset($_SESSION['user_id'])) {
            $this->user_id = $_SESSION['user_id'];
            $this->logged_in = true;
        } else {
            unset($this->user_id);
            $this->logged_in = false;
        }
    }
}

$session = new Session();
