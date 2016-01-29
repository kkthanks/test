<?php
$dsn = 'mysql:host=localhost;dbname=overlandoo';
// $dsn = 'mysql:host=localhost;dbname=overlandoo;port=3307';
// $dsn = 'sqlite:C:/xampp/htdocs/oophp/sqlite/oophp.db';

$db = new PDO($dsn, 'overlandooAdmin', 'passpass');

