#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

#include "structs.h"

t_map_data *get_data(char *file);
int parse_data(int fd, char *file, t_map_data *cub_data);
int get_fc(char *line, t_map_data *cub_data);
int get_textures(char* line, t_map_data *cub_data);
void get_map(char *file, t_map_data *cub_data);

#endif //CUB3D_PARSING_H
