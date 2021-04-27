# RDP_Executable_Application_With_Params
## Description:
  Use RDP apps like local applications on your computer, in command-line, and to "run with" option.<br>
## How it works:
  The application replicating herself to create a new application and inserting RDP file content into a variable inside the compiled application. On the execute it's saving RDP file on the drive with parameters and runs it.
  
## Use example:
  1. In RemoteApp Tool, add application like Edge, VLC, or Steam like on the photo below,<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116274443-f8ff4c80-a782-11eb-8621-c83b8c58e8f0.png)
  2. Click the app and "Create Client Connection..." to save an RDP file.
  3. If you want an icon on the application, extract the icon and save in RDP the directory with the same name, and put app "Resource hacker" with "rh.exe" name like on photos below,,<br>
  ![obraz](https://user-images.githubusercontent.com/26689155/116281799-58148f80-a78a-11eb-83db-05298833fdf2.png)
  ![obraz](https://user-images.githubusercontent.com/26689155/116281725-492ddd00-a78a-11eb-852a-33501772c7d7.png)
  4. To create an application from the ".rdp" file run command<br>
    AppRunner.exe <path_to_rdp_file> <output_path_for_exe_file><br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116282457-159f8280-a78b-11eb-967c-63164b455a70.png)
  5. The application will be generated like on the photo below,<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116282542-323bba80-a78b-11eb-8d05-1f85a5577709.png)
  6. Usage example on other pc,<br>
    a) Edge application<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116282835-8b0b5300-a78b-11eb-8e6a-24b044081e97.png)<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116282896-99596f00-a78b-11eb-834e-ae133b4cc20b.png)<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116282967-a8402180-a78b-11eb-8399-ce5570e1bce5.png)<br>
    b) VLC application<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116283300-05d46e00-a78c-11eb-82eb-99eab4a7c195.png)<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116283356-17b61100-a78c-11eb-929a-732f4cdc6ffc.png)<br>
    ![obraz](https://user-images.githubusercontent.com/26689155/116283395-200e4c00-a78c-11eb-9c3a-0de321521aff.png)<br>
 ## In Windows OS you can run with this app and it will work.<br>
 ## "Z:\" drive is used as a shared disk available on the app server.
 ## RDP file can't contains "remoteapplicationcmdline:s:" line.
