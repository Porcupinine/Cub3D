#!/bin/bash

# Path to the maps folder
maps_folder="maps/valid_maps"

# Check if the maps folder exists
if [ ! -d "$maps_folder" ]; then
    echo "Maps folder not found."
    exit 1
fi

# Loop through each file in the maps folder
for map_file in "$maps_folder"/*; do
    # Check if the file is a regular file
    if [ -f "$map_file" ]; then
        # Run the program with the map file as an argument
        ./cub3d "$map_file" &
        # Wait for a moment to ensure the program starts
        sleep 2
        # Send Escape key to close the program
        xdotool key Escape
        # Wait for the program to close
        sleep 1
    fi
done