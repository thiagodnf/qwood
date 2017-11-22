# qwood
qt-based

## Install

Follow the steps to run the app

### Step 1) Installing Qt

```sh
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
```

Adjust permission

```sh
chmod +x qt-opensource-linux-x64-5.7.0.run
```

Run the installer and follow the instruction to complete the installation.

```sh
./qt-opensource-linux-x64-5.7.0.run
```

### Step 2) Installing C++

Open a terminal and execute the following command to install g++:

```sh
sudo apt-get install build-essential
```

### Step 3) Installing generic font configuration library - runtime

Open a terminal and execute the following command to install the full runtime files for the generic font configuration library:

```sh
sudo apt-get install libfontconfig1
```

### Step 4) Installing OpenGL libraries

Execute the following command to install OpenGL libraries

```sh
sudo apt-get install mesa-common-dev libglu1-mesa-dev
```
