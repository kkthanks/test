<?php
require_once('core_paths.php');

class Upload extends User
{
    // class has to be associated with a user
    // must have user id first before can upload photo
    // there will be no "create" function since when a user join, it will auto create already, so only "update" function
    // might not even need an upload class, can just migrate everything into user class

    protected static $table_name = "users";
    // only avatar is needed for upload
    protected static $db_fields = array('id', 'avatar');

    public static $max_file_size = 1048576; //bytes: 1mb is 1,048,576 bytes

    public $id;
    public $type;
    public $size;
    public $avatar;
    private $temp_path;
    public $errors = array();

    protected $upload_errors = array(
    // http://www.php.net/manual/en/features.file-upload.errors.php
    UPLOAD_ERR_OK         => "No errors.",
    UPLOAD_ERR_INI_SIZE   => "Larger than upload_max_filesize.",
    UPLOAD_ERR_FORM_SIZE  => "Larger than form MAX_FILE_SIZE.",
    UPLOAD_ERR_PARTIAL    => "Partial upload.",
    UPLOAD_ERR_NO_FILE    => "No file.",
    UPLOAD_ERR_NO_TMP_DIR => "No temporary directory.",
    UPLOAD_ERR_CANT_WRITE => "Can't write to disk.",
    UPLOAD_ERR_EXTENSION  => "File upload stopped by extension."
    );

    public $upload_dir = 'images';
    
    // default image every user will get at first
    // if file with $username_filename.jpg exist, use that, if not use default.jpg
    public function defaultImage()
    {
        if (glob(SITE_ROOT.DS.'public'.DS.$this->upload_dir.DS."{$this->user_name}_*.jpg")) {
            return $this->imagePath();
        } else {
            return $this->upload_dir.DS."default.jpg";
        }
    }

    // create a file name with the user name at the front and his original file name at the end
    public function imagePath()
    {
        return $this->upload_dir.DS.$this->user_name.'_'.$this->avatar;
    }

    public function targetPath()
    {
        return SITE_ROOT.DS.'public'.DS.$this->imagePath();
    }
    // if file on database's avatar is same as the one in the folder
    public function fileExist()
    {
        if (glob(SITE_ROOT.DS.'public'.DS.'images'.DS."{$this->user_name}*.jpg")) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * pass in $_FILE(['uploaded_file']) as argument
     * @param  [type] $file [description]
     * @return [type]       [description]
     */
    public function attachFile($file)
    {
        // perform error checking on form parameters
        if (!$file || empty($file) || !is_array($file)) {
            $this->errors[] = "No file was uploaded";
            return false;
        } elseif ($file['error'] != 0) {
            // error: report what PHP says went wrong
            $this->errors[] = $this->upload_errors[$file['error']];
            return false;
        } else {
            $this->temp_path = $file['tmp_name'];
            $this->avatar = basename($file['name']);
            $this->type = $file['type'];
            $this->size = $file['size'];
            return true;
        }
    }

    public function uploadPhoto()
    {

        // make sure there are no errors
        if (!empty($this->errors)) {
            return false;
        }
        // make sure it has a file name and temp location
        if (empty($this->avatar) || empty($this->temp_path)) {
            $this->errors[] = "file location not avaliable";
            return false;
        }

        // make sure file doesn't already exist
        if (file_exists($this->targetPath())) {
            $this->errors[] = "The file {$this->avatar} already exists.";
            return false;
        }

        // move the uploaded file from temp dir to your dir
        if (move_uploaded_file($this->temp_path, $this->targetPath())) {
            // success
            // save entry to database
            if ($this->update()) {
                // can delete temp path cuz the file is not there anymore
                unset($this->temp_path);
                //unlink($target_path);
                return true;
            }
        } else {
            // file was not moved
            $this ->errors[] = "File upload failed, maybe due to incorrect permissions on folder";
            return false;
        }
    }

    public function destroy()
    {
        global $db;
        // first change database entry 'avatar' to NULL
        // then remove the file
        unlink($this->targetPath());
        if ($db->exec("UPDATE ".static::$table_name." SET avatar="."'default.jpg'"." WHERE id=".$this->id)) {
            return true;
        } else {
            return false;
        }
    }

    /** good to have but not using it just yet */
    public function sizeAsText()
    {
        if ($this->size < 1024) {
            return "{$this->size} bytes";
        } elseif ($this->size < 1048576) {
            $size_kb = round($this->size/1024);
            return "{$size_kb} KB";
        } else {
            $size_mb = round($this->size/1048576, 1);
            return "{$size_mb} MB";
        }
    }
}
