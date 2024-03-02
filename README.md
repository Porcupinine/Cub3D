# **Cub3D**

### Overall
This was the second group project at Codam, and it aims the creation of a 3D 
looking labyrinth inspired by the game Wolfenstein 3D. 
During this project we worked with the [MLX42 library](https://github.com/codam-coding-college/MLX42)
to emulate a 3D environment using Raycasting.

### Download and usage
You can [download](https://github.com/Porcupinine/Cub3D/archive/refs/heads/main.zip)
the zip version of the project or clone it using the terminal.
you can run the program with:
```console
./cub3d maps/valid_maps/"map_of_your_choice"
```
or you can create your own map, but it must follow some rules.

### What is a valid map
In case you want to make your own map, it is composed of two parts

**First part** is a set of paths to the textures that are going to be used for the 
walls and the RGB for the colors that will be used for the floor and the celling.
They are recognized by the program using key characters and the must be separated by
as many **empty lines** you desire. As key words we have:
* NO ./"path for north texture"
* SO ./"path for south texture"
* WE ./"path for west texture"
* EA ./"path for east texture"
* C "***R***ed value,***G***reen value,***B***lue value"
* F "***R***ed value,***G***reen value,***B***lue value"

It doesn't matter in which order they are put and you can have spaces between 
the coordinate and "./" for the textures but no extra spaces between the RGB values.

**Last part** The parsing of the map starts as son as we find a line 
that only contains, walls(1), walking spaces(0), and empty spaces " ". Of course the 
map also have to follow some rules:
* You must have one and only one player, and it is recognized by the letters 
N(north), S(south), E(east), W(west). The letter decides in which direction the player
will be looking at when the game starts.
* The map must be surrounded, AKA 0s and the player can only be in the middle part of the 
map and can't have an empty space as a neighbour.
* No more empty lines, not even a line at the end of the map.

For example of good maps, please check **maps/valid_maps**


### How raycasting works
Once we have our map is saved as an array of strings, and we know the position and orientation
of our player, we need to set a range of view and with the help of math we can determine which walls
we are looking at and how far we are form it. That point is going to be our x coordinate on the 3D view 
based on the distance we can calculate the height of the wall and start drawing it on our scree vertical line 
by vertical line. For more detailed explanation we recommend checking out the [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
and the [Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA&ab_channel=javidx9).

### **Sources**

[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)

[Cub3D Tutorial Using angles](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf)

[Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA&ab_channel=javidx9)

[Make Your Own Raycaster Part 1](https://www.youtube.com/watch?v=gYRrGTC7GtA&ab_channel=3DSage)

[itch.io](https://itch.io/game-assets/free/tag-animation/tag-fantasy)

[Ray casting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-19/#SHADING)

