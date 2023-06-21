# Rhythm

---

Note: This is an archive of rhythm, the ELEC 320 course project by Team 5 - Tango Nuevo. Credit to

- Michael Geddes
- Harrison Gordon
- Connor Massey
- Tony Zheng
- Nicholas Kriskapa
- Joe Ajoy
- Peter Danilin

---

Rhythm is the evolution in playlist generation.  Rhythm is currently in version 1.1.  This master branch is a working copy
of the software.  Releases can be found in the "release" zip file in the following branches.

## Release History
- [rhythm-1.0](http://jira.caslab.queensu.ca:7990/projects/TN/repos/rhythm/browse?at=refs%2Fheads%2Frhythm-1.0) - November 29 2021
- [rhythm-1.1](http://jira.caslab.queensu.ca:7990/projects/TN/repos/rhythm/browse?at=refs%2Fheads%2Frhythm-1.1) - November 30 2021

## Setup
1) [Download Qt 5 Open Source Online Installer.](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)  
2) When installing Qt 5, do a custom install.  When on the "Select Components" window, uncheck everything. Next, click
LTS.  Then open the drop down for Qt -> Qt 5.15.2 -> select the binary you want to download (If you are using CLion on
windows, you are going to want MinGW 8.1.0 64-bit)
3) You will need to set the CMAKE_PREFIX_PATH in order to use the Qt Libraries.  If you are using CLion, go to Settings
-> Build, Execution, Deployment -> CMake -> CMake Options and add: **-D CMAKE_PREFIX_PATH=Path to Qt install**.  If you 
installed it to C:\Qt\ it should look something like this: **-D CMAKE_PREFIX_PATH=C:\Qt\5.15.2\mingw81_64\lib\cmake**
4) If you try to run the code and you get an error "*Process finished with exit code -1073741515 (0xC0000135)*", try [these
trouble shooting steps.](https://www.jetbrains.com/help/clion/qt-tutorial.html#troubleshooting)
