<?php
$con=mysqli_connect('localhost','root','','robospark');
if(!$con)
{
    echo "connection error".mysqli_connection_error();
}
else{
    echo "<h3> Database connection success</h3>";
}
if(isset($_POST['submit']))
{
    $user=$_POST['user_id'];
    $query="SELECT * FROM `task` WHERE `user_id`='$user'";
    $run = mysqli_query($con,$query);
    $row=mysqli_num_rows($run);
	if($row==1)
	{
		$_SESSION['user_id']=$user;
		echo "success"."\n";
		$user_row=mysqli_fetch_assoc($run);
		echo $user_row['user_id']."->".$user_row['student_name']."->".$user_row['branch']."->".$user_row['cgpa'];
	}
	else
	{
	 echo "login unsuccessful"	;
	}

}
?>