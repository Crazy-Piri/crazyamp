# Crazy Piri Music Player

Arkos music player for Amstrad CPC

## How to create your crazyamp disk ?

### Install docker

### Create the json file
Copy the .aks song file in a directory and, from this directory, run the command
```
docker run --rm -v ${PWD}:/src/ -it redbug26/crazyamp cp_create
```

### Edit the json file with your preference (optional)
edit the json 

```
docker run --rm -v ${PWD}:/src/ -it redbug26/crazyamp cp_refresh
```

Use the generated .dsk file in your prefered Amstrad emulator (or use it on true device!)

#### Note for Windows: Replace `${PWD}` with `%cd%` in all commands

# Credits

- Original player source and tracker by Targhan/Arkos
