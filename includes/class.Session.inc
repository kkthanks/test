<?php

class Session
{

    // most of the functions should be done from an instantiated sessions class
    // no point leaving any info in session using static attributes or methods
    
    private $logged_in = false;
    public $user_id;
    public $message;

    public function __construct()
    {
        session_start();
        $this->checkMessage();
        $this->checkLogin();
        if ($this->logged_in) {
            // actions to take when user is logged in
        } else {
            // actions to take when user is not logged in
        }
    }

    public function isLoggedIn()
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

    /** can do both get and set message */
    public function message($msg = "")
    {
        if (!empty($msg)) {
            // then this is a "set" message
            $_SESSION['message'] = $msg;
        } else {
            // this is a 'get' message
            return $this->message;
        }
    }

    private function checkLogin()
    {
        if (isset($_SESSION['user_id'])) {
            $this->user_id = $_SESSION['user_id'];
            $this->logged_in = true;
        } else {
            unset($this->user_id);
            $this->logged_in = false;
        }
    }

    private function checkMessage()
    {
        // is there a message stored in the session?
        if (isset($_SESSION['message'])) {
            // add the stored $_SESSION message into the session class's $message and erase the stored version
            $this->message = $_SESSION['message'];
            unset($_SESSION['message']);
        } else {
            // initialise message with empty string
            $this->message = "";
        }
    }
}

$session = new Session();
$message = $session->message();
