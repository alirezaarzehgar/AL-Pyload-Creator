                                << in the name of god >>

## Document
        I am alireza arzehgar.
        AL-Pyload-Creator can create pyload and malware :
	- pyload for linux
	- pyload for server
	- php shell
	- virus for linux

	getting access from another systems and remot Linux desktop:).

## using
	$ ./AL-Pyload-Creator [OPTIONS]

## create pyload
	$ ./AL-Pyload-Creator -m tc

## getting access
	$ ./AL-Pyload-Creator -m ga

## options
	-o --os   : this parametr can setting oprating system of target program (but not write for another os and defualt os is Linux)
	-i --ip   : this parametr can setting ip for connection target with you. you can Enter your ip
	-p --port : this parametr cat setting port for two program for create a socket.
	-n --name : this parametr cat setting target program name
	-m --mode : this parametr can choose model of program work, if you write [--mode tc/targetCreate] program create a target program
		    and if you write [--mode ga/gettingAccess] program getting access from target program
		   
## github link
        - link : https://github.com/alirezaarzehgar/AL-Pyload-Creator.git

## Dependencies
        - gcc

## installing
        ```
	$ cd AL-Pyload-Creator
	$ make
        $ ./AL-Pyload-Creator [arguments]
        ```

