# Cinnamon Checker
The Cinnamon Checker is a simple program designed to check if the Cinnamon desktop environment is running on Linux. If Cinnamon is not running, the program restarts the environment to ensure its proper functioning.
# Compilation
To compile the program, follow the steps below:
  ```shell
    $ git clone https://github.com/brunoribeiro-lab/cinnamon-checker # (or use the ssh link)
    $ cd cinnamon-checker/
    $ sudo gcc init.c -o /usr/local/bin/cinnamon-checker
  ```
# Usage
1) After compilation, you can use the Cinnamon Checker to check and restart the Cinnamon desktop environment if needed.
Run the program:
  ```shell
    $ ./cinnamon-checker
  ```
2) The program will check if Cinnamon is running. If it is, it will display a message indicating that the environment is running.
3) If Cinnamon is not running, the program will automatically restart it.
# Automatic Scheduling
To facilitate the use of the Cinnamon Checker, you can schedule its automatic execution using the cron utility on Linux. Cron allows you to schedule tasks to run at regular intervals.
1) Open the cron configuration file using the following command:
  ```shell
    $ sudo crontab -e
  ```
2) Add the following line at the end of the file:
  ```
  * * * * * /usr/local/bin/cinnamon-checker
  ```
Make sure to replace "/path/to/cinnamon-checker" with the full path to the Cinnamon Checker executable on your system.

3) Save the file and close the editor.

Now, cron will automatically run the Cinnamon Checker every minute to check and restart the Cinnamon environment if needed.

# Conclusion
The Cinnamon Checker is a useful tool to ensure that the Cinnamon desktop environment is always running properly. By following the compilation and automatic scheduling steps, you can automate the process of checking and restarting Cinnamon to maintain a stable working environment.
