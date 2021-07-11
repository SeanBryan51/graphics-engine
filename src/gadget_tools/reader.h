#pragma once

// Header for the standard file format (see
// Gadget source code).
typedef struct Header {

  int npart[6];
  double mass[6];

  double time;
  double redshift;
  int flag_sfr;
  int flag_feedback;
  unsigned int npartTotal[6];

  int flag_cooling;
  int num_files;
  double BoxSize;
  double Omega0;
  double OmegaLambda;
  double HubbleParam;
  int flag_stellarage;
  int flag_metals;
  unsigned int npartTotalHighWord[6];
  int  flag_entropy_instead_u;
  char fill[60];
  
} Header;

Header  read_header(char * file);
float * read_positions(char * file);
float * read_velocities(char * file);

void    header_show_details(Header h);
int     header_get_n_particles(Header h);
double  header_get_time(Header h);
double  header_get_redshift(Header h);
double  header_get_boxsize(Header h);
double  header_get_matter_density(Header h);
double  header_get_dark_matter_density(Header h);

