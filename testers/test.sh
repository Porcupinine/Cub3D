#!/bin/bash

# Function that Loops through each file
function loops() {
  # Check if the maps folder exists
  if [ ! -d "$maps_folder" ]; then
      echo "Maps folder not found."
      exit 1
  fi
  for map_file in "$maps_folder"/*; do
      # Check if the file is a regular file
      if [ -f "$map_file" ]; then
          echo "$map_file"
          # Run the program with the map file as an argument
          .././cub3d "$map_file" &
          # Store the process ID of the program
          pid=$!
          # Wait for a moment to ensure the program starts
          sleep 2
           # Check if the process exists before trying to kill it
          if kill -0 "$pid" > /dev/null 2>&1; then
            # Send signal to close the program
            kill -SIGTERM "$pid"
            # Wait for the program to close
            wait "$pid"
          fi
          # Wait for the program to close
          sleep 1
          # Add a couple of new lines
          echo -e "\n\n"
      fi
  done
}

# Path to the maps folder
maps_folder="../maps/invalid_maps"
loops
maps_folder="../maps/valid_maps"
loops
