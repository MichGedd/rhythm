# Rhythm
Description here

##Setup
1) [Download Qt 5 Open Source Online Installer.](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)  
2) When installing Qt 5, do a custom install.  When on the "Select Components" window, uncheck everything. Next, click
LTS.  Then open the drop down for Qt -> Qt 5.15.2 -> select the binary you want to download (If you are using CLion on
windows, you are going to want MinGW 8.1.0 64-bit)
3) You will need to set the CMAKE_PREFIX_PATH in order to use the Qt Libraries.  If you are using CLion, go to Settings
-> Build, Execution, Deployment -> CMake -> CMake Options and add: **-D CMAKE_PREFIX_PATH=Path to Qt install**.  If you 
installed it to C:\Qt\ it should look something like this: **-D CMAKE_PREFIX_PATH=C:\Qt\5.15.2\mingw81_64\lib\cmake**
4) If you try to run the code and you get an error "*Process finished with exit code -1073741515 (0xC0000135)*", try [these
trouble shooting steps.](https://www.jetbrains.com/help/clion/qt-tutorial.html#troubleshooting)