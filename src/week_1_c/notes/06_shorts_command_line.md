# Command line

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

The CS50 IDE is a cloud-based machine running Ubuntu, one of the many flavors of the Linux OS.

Many modern Linux distributions have graphical user interfaces (GUI) to allow easy mouse-based navigation.

Still, as a programmer you’ll likely be using your terminal window frequently, and you can do many of the same tasks
with keyboard commands.

---

Let’s have a look at some of the most important of these keyboard-based commands for working within the IDE
or any UNIX-based system.

## ls

Short for “list”, this command will give you a readout of
all the files and folders in your current directory

## cd < directory >

Short for “change directory”, this command change your
current directory to < directory >, which you specify,
in your workspace or on your operating system.

- The shorthand name for the current directory is ...
- The shorthand name for the parent directory of the
current directory is ...

If ever curious about the name of the current directory,
though the terminal prompt will often tell you, you can
type pwd (present working directory).

## mkdir < directory >

Short for “make directory”, this command will create a new subdirectory called < directory > located
in the current directory.

## cp < source > < destination >

Short for “copy”, this command will allow you to create a
duplicate of the file you specify as < source >, which it
will save in < destination >.

If you wish to copy entire directories, you’ll need to
modify the command slightly:

    cp –r < source directory > < destination directory >

The “-r” stands for recursive, and tells cp to dive down
into the directory and copy everything inside of it
(including any subdirectories it might contain).

## rm < file >

Short for “remove”, this command will delete < file >
after it asks you to confirm (y/n) you want to delete it.

You can skip the confirmation by typing:

    rm –f < file >

But use at your own peril! There’s no undo.

To delete entire directories you need to use the –r flag,
just as was the case with cp.

    rm –r < directory >

You can also combine the –r and –f flags into –rf.
Again, careful! There’s no undo!

## mv < source > < destination >

Short for “move”, this command will allow you to effectively rename a file, moving it from < source > to < destination >.

---

## Other

### chmod

Used to modify the permissions and access mode of files and directories.
[Link](https://linuxize.com/post/chmod-command-in-linux/)

```c
chmod +rwx filename // to add permissions.
chmod -rwx directoryname // to remove permissions.
chmod +x filename // to allow executable permissions.
chmod -wx filename // to take out write and executable permissions.

    -    // indicates a file
    d    // indicates directory
    l    // indicates a link
    rwx    // read, write and execute permissions for the owner of the file
    r--    // read, write and execute permissions for members of the group owning the file
    r--    // read, write and execute permissions for members of other users
```

Three options for permission groups:

- ***Owners***: only apply to owners.
- ***Groups***: specific permissions to a group of users.
- ***All users***: apply to all users, present the greatest security risk.

### ln

Used to create a hard link or a symbolic link (symlink) to an existing file or directory.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=l-ln-command)

```c
ln -s [OPTIONS] FILE LINK
```

- If both the FILE and LINK are given, *'ln'* will create a link from the file specified as the first argument (FILE)
to the file specified as the second argument (LINK).
- If only one file is given as an argument or the second argument is a dot (.), *'ln'* will create a link to that file
in the current working directory . The symlink will have the same name as the file it points to.

### touch

Updates the access and modification times of a file.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=t-touch-command)

```c
touch <options> <file or directory name>
```

### rmdir

Remove the directory, specified by the Directory parameter, from the system.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=r-rmdir-command)

- The ***rm*** command removes complete directories, including subdirectories and files.
- The ***rmdir*** command removes empty directories.

```c
rmdir [<drive>:]<path> [/s [/q]]
```

| Parameter             | Description                                                                                                                                                                                                                                             |
|-----------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [< drive >:] < path > | Specifies the location and the name of the directory that you want to delete. Path is required. If you include a backslash () at the beginning of the specified path, then the path starts at the root directory (regardless of the current directory). |
| /s                    | Deletes a directory tree (the specified directory and all its subdirectories, including all files).                                                                                                                                                     |
| /q                    | Specifies quiet mode. Does not prompt for confirmation when deleting a directory tree. The /q parameter works only if /s is also specified.                                                                                                             |
| /?                    | Displays help at the command prompt.                                                                                                                                                                                                                    |

### man

Displays manual entries online.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=m-man-command)

```c
man [option] [command]
```

### diff

Compares text files.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=d-diff-command)

```c
diff [OPTION]... FILE1 FILE2
```

### sudo

Allows you to run programs as another user, by default the root user.
[Link](https://linuxize.com/post/sudo-command-in-linux/)

```c
sudo OPTION.. COMMAND
```

### clear

Clears the terminal screen.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=c-clear-command)

    clear

### telnet

Connects the local host with a remote host, using the Telnet interface.
[Link](https://www.ibm.com/docs/en/aix/7.2?topic=t-telnet-command)

> **Not a secure protocol!** Data is unencrypted.

