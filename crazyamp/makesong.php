<?php

// var_dump($argv);
//
function getSongList($file) {

$zip_obj = new ZipArchive;
$zip_obj->open($file);

for( $i = 0; $i < $zip_obj->numFiles; $i++ ){
    $stat = $zip_obj->statIndex( $i );
    $aks_file = "/tmp/" .  basename( $stat['name'] );
}

$zip_obj->extractTo('/tmp');

$xml = simplexml_load_file($aks_file, null, null, 'aks', true);

//print_r($xml);
//
$id = 1;

$retour = array();

foreach($xml->subsongs->subsong as $subsong) {
	$retour[$id] = $subsong->title->__toString();
        $id++;
}


return $retour;
}


function convertname($name)
{
    $result = strtoupper($name);
    $result = substr($result, 0, 32);
    $result = str_pad($result, 32, " ");

    return $result;
}

if ((array_key_exists('1', $argv)) && ($argv["1"] != "")) {
    $dir = $argv["1"];
} else {
    $dir = ".";
}
$dir = realpath($dir);

$fp = @fopen('/src/crazyamp.json', 'r');
if ($fp !== false) {
    $contents = fread($fp, filesize('/src/crazyamp.json'));
    fclose($fp);

    $output = json_decode($contents, true);
} else {
    $output = array();
}

// print_r($output);exit;

echo "Reading: " . $dir . PHP_EOL;

$songs = array_key_exists('songs', $output) ? $output["songs"] : array();

// print_r($songs);exit;

$handle = opendir($dir);
while (false !== ($readdir = readdir($handle))) {
    if ($readdir != '.' && $readdir != '..') {
        $path = $dir . '/' . $readdir;

        $path_parts = pathinfo($path);

        // print_r($path_parts);

        $extension = array_key_exists('extension', $path_parts) ? strtolower($path_parts['extension']) : "";

        if ((is_file($path)) && ($extension == "aks")) {

            $found = false;
            foreach ($songs as $k => $song0) {
                if ($song0["path"] == $path) {
                    // $song = $song0;
                    // unset($songs[$k]);
                    $found = true;
                    break;
                }
            }

	    if (!$found) {
		    $rows = getSongList($path);
		    foreach($rows as $key => $value) {
                $song = array();
                $song["path"] = $path;
		$song["sub"] = sprintf("s%dp1", $key);
                $song["name"] = $value; //  $path_parts["filename"];
		$songs[] = $song;
		}
            }

        }
    }
}
closedir($handle);

$output["songs"] = $songs;

$fp = fopen('/src/crazyamp.json', 'w');
fwrite($fp, json_encode($output, JSON_PRETTY_PRINT));
fclose($fp);

// Create build_song

$fp = fopen('song/build.sh', 'wt');
fprintf($fp, "#!/bin/bash\n");
fprintf($fp, "\n");

fprintf($fp, "SONGTOAKG=/tmp/tools/bin/x86_64/SongToAkg\n");
fprintf($fp, "DISARK=/tmp/tools/bin/x86_64/Disark\n");

foreach ($songs as $k => $song) {
    fprintf($fp, "echo \"Convert %s\"\n", $song["name"]);
    fprintf($fp, "\$SONGTOAKG -sp %s -spskipcom --exportPlayerConfig --labelPrefix song%02d_ \"%s\" song%02d.asm\n", $song["sub"], $k, $song["path"], $k);
}

fprintf($fp, "\n");
fprintf($fp, "\n");
fprintf($fp, "rasm PlayerAndMusic.asm -o PlayerAndMusic -s -sl -sq\n");
fprintf($fp, "\n");
fprintf($fp, "\$DISARK PlayerAndMusic.bin Final.asm --symbolFile PlayerAndMusic.sym --sourceProfile sdcc\n");
fprintf($fp, "\n");
fprintf($fp, "mv Final.asm arkostracker2.s\n");
fprintf($fp, "\n");
fprintf($fp, "rm -f song*.asm\n");
fprintf($fp, "rm -f PlayerAndMusic.sym\n");
fprintf($fp, "rm -f PlayerAndMusic.bin\n");
fclose($fp);

chmod("song/build.sh", 755);

// Create build_song

$fp = fopen('song/PlayerAndMusic.asm', 'wt');

fprintf($fp, "PLY_AKG_HARDWARE_CPC = 1\n");
fprintf($fp, "PLY_AKG_MANAGE_SOUND_EFFECTS = 1\n");

foreach ($songs as $k => $song) {
    fprintf($fp, "include \"song%02d_playerconfig.asm\"\n", $k);
}

fprintf($fp, "include \"PlayerAkg.asm\"\n");

foreach ($songs as $k => $song) {
    fprintf($fp, "include \"song%02d.asm\"\n", $k);
}

fprintf($fp, "include \"emptySong.asm\"\n");
fprintf($fp, "include \"SoundEffects.asm\"\n");

fclose($fp);

// Create source

$fp = fopen('src/song.h', 'wt');
fprintf($fp, "#define NBR_SONG %d\n", count($songs));
fprintf($fp, "\n");
fprintf($fp, "void loadSong(char song)\n");
fprintf($fp, "{\n");
fprintf($fp, "\n");
fprintf($fp, "\n");

$i = 0;
foreach ($songs as $k => $song) {

    fprintf($fp, "if (song == %d) {\n", $i);
    fprintf($fp, "         #ifdef SOUND\n");
    fprintf($fp, "        __asm\n");
    fprintf($fp, "        push af\n");
    fprintf($fp, "        push bc\n");
    fprintf($fp, "        push ix\n");
    fprintf($fp, "        push iy\n");
    fprintf($fp, "\n");
    fprintf($fp, "        ld hl, #_SONG%02d_START\n", $k);
    fprintf($fp, "        xor a, a\n");
    fprintf($fp, "        call _PLY_AKG_INIT\n");
    fprintf($fp, "\n");
    fprintf($fp, "        ld hl, #_SOUNDEFFECTS_SOUNDEFFECTS\n");
    fprintf($fp, "        xor a, a\n");
    fprintf($fp, "        call _PLY_AKG_INITSOUNDEFFECTS\n");
    fprintf($fp, "\n");
    fprintf($fp, "\n");
    fprintf($fp, "        pop iy\n");
    fprintf($fp, "        pop ix\n");
    fprintf($fp, "        pop bc\n");
    fprintf($fp, "        pop af\n");
    fprintf($fp, "           __endasm;\n");
    fprintf($fp, "#endif /* ifdef SOUND */\n");
    fprintf($fp, "    }\n");

    $i++;
}

fprintf($fp, "}\n");
fprintf($fp, "\n");
fprintf($fp, "\n");
fprintf($fp, "void dispTitle(u8 n, u8 pos, u8 active)\n");
fprintf($fp, "{\n");
fprintf($fp, "switch (n) {\n");

$i = 0;
foreach ($songs as $k => $song) {

    fprintf($fp, "        case %d:\n", $i);
    fprintf($fp, "            k_PrintGphStr8x8(\"%s\", 6, 142 + pos * 7, active);\n", convertname($song["name"]));
    fprintf($fp, "            break;\n");
    $i++;
}
fprintf($fp, "\n");
fprintf($fp, "}\n");
fprintf($fp, "} /* dispTitle */\n");

fclose($fp);

echo count($songs) . " songs found" . PHP_EOL;
