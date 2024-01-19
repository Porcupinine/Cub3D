#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

typedef struct parse_data {
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	int					*floor;
	int 				*celling;
	char				**map;
}t_parse_data;

t_parse_data *get_data(char *file);
int get_fc(char *line, t_parse_data *cub_data);
int get_textures(char* line, t_parse_data *cub_data);
int get_map(int fd, t_parse_data *cub_data);

#endif //CUB3D_PARSING_H
