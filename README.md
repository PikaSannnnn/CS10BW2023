# CS10BW2023
## Table of Contents
* [GitHub for SI](#github-for-si)
* [Setting up a GitHub Key](#setting-up-a-github-key)
* [Using GitHub](#using-github)
* [Useful Commands](#useful-commands)
  * [Compiling the Code](#compiling-the-code)
  * [Running the Code](#running-the-code)
  * [Terminal Commands](#terminal-commands)
* [Filestreams](#file-streams)
* [Command Line Args](#command-arguments)

## GitHub for SI
There's quite a lot with GitHub that is really important to know. The first and foremost is the fact that GitHub uses this thing called `git`. From your terminal you will do everything through this `git` command. These commands will be explained in the **[Using GitHub](#using-github)** section.  
The main importance in this section is how GitHub will be used for SI. From now on, what you'll do when coming to session is to open this GitHub and stay on the main page. Likewise, open your version of the repository that is on either your local machine or the cs010b server. You will be coding using the template files that I provide or we will continue with a previous activity.  

**Make sure that you are ALWAYS working on your own branch.**

I will also be putting solutions to the code to practice activities that we *have gone over and have already seen the solution in session*.
 
## Setting up a GitHub Key
Whenever you wish to push something, you have to login. As of 2020, for absolutely no reason, you cannot use your own GitHub password anymore. Instead, you have to use a token key. You can go [here](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token) to setup a key. Keep this safe with you at all times; otherwise, you'll have to keep making new keys, and no one likes that.  

The other option is to permanently link a specific server by generating a ssh key (derived from cs142 instructions):
1. You can do this by typing `ssh-keygen -t rsa` in your server terminal to generate a key pair  
2. Get the key generated by typing and copying the output from `cat ~/.ssh/id_rsa.pub`
3. Next, go to GitHub -> settings -> SSH and GPG keys. Click ???New SSH key???. Paste the public key into field ???Key???, and give it a name you like.
4. With this, you can now just `git clone <ssh link>` and similar git commands easily as long as you used the **ssh link** (which can be found in the same green "code" button, but under the `ssh` tab instead.
## Using GitHub
GitHub is useful for version control. Everyone will have their own version with their own branches. To start, you'll need to clone this repo:
```
git clone <https/ssh link>
```

Next, you'll need to create a branch:
```
git branch <NetID>
```
Example: `git branch adoo001`  
You can check if the branch was successfully created if you see your branch name when typing:
```
git branch
```

You will then need to enter your branch with:
```
git checkout <branch name>
```
You will know which branch you are currently in when typing `git branch`. An asterick * will be next to the branch name that you are currently in. Make sure you are in your **NetID** branch.

From now on, changes you make will be on this branch only. If there's ever a new file or an updated file that *you have not edited*, I will announce it and you will be able to see it in main.  
First, make sure you're in your branch. Then type this:
```
git rebase main
```

If you or someone posted changes to github on your branch, you can use:
```
git pull
```
This pulls the changes that were made and commited to the repo for that branch.

You've seen or heard "commit" a couple of times now, that's because you have to commit changes to push onto the repo. First you want to add the changes you'd like to have show up on the repo.  
Type the following to see the status of all files and to see what has been tracked and what has been changed.
```
git status
```

Now, you need to add changes to be committed. You'll have to manually input the files.
```
git add <file1> <file2> ...
```
However, if you know everything you want on the repo is there, you can type this instead
```
git add .
```
Or
```
git add *
```
As explained in a later section, `*` means "everything". However, there are files and directories that are hidden. These files have a `.` in front and typically aren't added when doing `*`. If you have files like `.gitignore`, or your own meta files that are hidden and you want these to be added along with everything, use `.` instead.

Now, you can commit with the following code:
```
git commit
```
This will open a vim or nano editor in your termina. You can add a title on the first line, and the next few lines are descriptions. To exit out of **`nano`**, you would press `ctrl + x`. To exit out of **`vim`**, which is what you'll most likely be in, press `esc`, then `:`, then enter `wq` and press enter. You don't need to know what any of this does, but it may be nice to learn eventually, so I'd suggest learning about it.

If you don't want to go through the whole process of titling and describing, you can just do this instead
```
git commit -m "<message>"
```
This way, you can type a short message instead in one line in between the quotes and be done. Be aware there is a character limit.

Now that you've committed, you will need to push with
```
git push
```

However, push only works if your branch was published. In this case, you'll need to publish your branch first with this:
```
git push -u origin <branch name>
```

**The following two, you will most likely never use.**

If there's ever a time you need to revert back to whatever was saved on the repo and revert **ALL** changes **AND** commits you've made since that version, you can type this:
```
git reset --hard
```

But what if we just want to undo the last **commit** instead of everything. You can type this instead:
```
git reset --soft
```

You don't need to know what any of these commands actually mean yet, but I'd suggest you try reading up on them sometime.
## Useful Commands:
### Compiling the Code
MacOS/Linux:  
```
g++ -std=c++17 main.cpp
```
Windows:  
```
g++ main.cpp
```
### Running the Code
MacOS/Linux:  
```
./a.out
```
Windows:  
```
a.exe
```

### Terminal Commands
* `pwd` - Print Working Directory: displays currently directory
* `ls` - List: lists directories and files in current director
  * Appending `-l` displays directories and files w/ permissions & last edit time
  * Appending `-a` displays all directories and files **including hidden files**
  * Appending `-la` or `al` combines the power of `-l` and `-a`
  * Appending a folder name (i.e. `ls home/` lists files in that directory without entering it)
* `cd` - Change Directory: changes working directory
  * `cd ..` exits current directory and enters previous direct
    * If you are in `home/homework`, typing `cd ..` will take you to `home/`
  * `cd` by itself or `cd ~` changes working directory to ROOT directory
  * Appending a directory path will take you directly to that directory
    * ex) `cd home/homework/CS10B` takes you to the CS10B folder in homework, which is in home
    * `..` can be used as well
      * ex) If you're in `home/homework/CS10B`, typing `cd ../../labs` will take you to the labs folder in `home`
* `mkdir` Creates a directory given a name
* `touch` Creates a file given a name (must include file type in name)
* `cp` Copies a file into a specified directory
  * ex) `cp main.cpp ../homework/CS10B`
* `rm` Removes a FILE
  * appending `-rf` will remove a FOLDER and all contents within (You don't get a confirmation message)
* `mv` Moves a file into a specified directory
  * ex) `mv main.cpp ../homework/CS110B`
  * Specifying another file name will *rename* the file
    * ex) `mv main.cpp run.cpp`
* `cat` Displays all contents within the specified file onto the terminal
* `nano` or `vim` Opens the specified file in an in-terminal file editor
  * Note: Nano is more simple than vim; vim focuses on keeping your hands on the home-row, which means your arrow movements use the homerow
* `g++ -Wall -Werror main.cpp -o run.out` Compiles a C++ code
  * `-Wall` tells compiler to display all warnings into the terminal
  * `-Werror` tells compiler to treat all warnings as errors
  * `-o` tells compiler to create executable using following argument
    * `-o run.out` creates a `run.out` executable rather than the default `a.out`


**Useful Tips**
* If you want to learn makefiles, you can go [here](https://makefiletutorial.com/). Makefiles are essential a script that compiles and sets up everything that is needed to create your runnable code.
* Compiling multiple files is like this: `g++ main.cpp a.cpp b.cpp`. If you know you want to compile every `.cpp` file in the directory, do this instead `g++ *.cpp`. `*` in CS is universal for "Everything", and doing `*.cpp` means "Everything with `.cpp` as the extention.


## File Streams
* `#include <fstream>` is needed to use the file stream
* `ifstream` is for inputting/reading from the file (similar to `cin`)
* `ofstream` is for outputting/writing to the file (similar to `cout`)
* `fstream` is the default (blank state) of `ofstream` and `ifstream`
    * A stream buffer labeled using `fstream` is by default bidirectional, you must declare a specific direction using a flag
* When opening a file flags can be set for the stream buffer.
  * ios::in - sets the stream buffer as input (default for ifstream)
  * ios::out - sets the stream buffer as output (default for ofstream)
  * ios::app - sets all output operations at the end of the file (append)
      * Only the operations are done at the end of the file
  * ios::ate - sets the output position at the end of the file
  * [Other Modes/Flags](http://www.cplusplus.com/reference/fstream/fstream/fstream/)
* Every file stream has its own methods (similar to string and vector)
  * `.open(<filename>, <flag(1) | flag(2) | ...>)`
      * Note: files can also be opened when declaring the stream buffer i.e. `ifstream fin(<filename>, <flag(1) | ...>)`
  * `.is_open()` returns false if file did not opene correctly or could not be opened, true otherwise
  * `.close()` closes the file and makes it available to use for other uses
  * `.ignore()` reads and ignores next input, or for parameters `(<max num char to skip>, <char to skip to>)`
  * `.eof()` checks if the eof bit was set
      * Note: Returns a bool, but is best **not** to be used with loops as bugs often occur
  * `.clear()` resets state bits
  * `.good()` returns true if good bit is 1
  * `.bad()` returns true if bad bit is 1
  * `.fail()` returns true if fail bit is 1
  
## Command Arguments
* To read arguments from command line `int argc, char* argv[]` must be set as `main()`'s parameters
  * Note: `char* argv[]` is interchangable with `char** argv`
  * When running the program, everything in the command line is read and stored in `argv[]`
  * `char* argv[]` is a c-string and behaves similar to strings included in `<string>`
  * `./a.out` will also be stored (as the first argument)
* Always check that there is enough arguments and/or the argument exists before trying to access it

