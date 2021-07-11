#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "reader.h"

#define N_PARTICLE_TYPES 6

Header read_header(char * file) {

    FILE * fp = fopen(file, "r");
    Header ret;

    // Check file can be read:
    assert(fp != NULL);

    // Read the block size for header structure and
    // move file pointer position to location of header:
    int blocksize;
    fread(&blocksize, sizeof(int), 1, fp);

    // Read in the header structure:
    fread(&ret, sizeof(Header), 1, fp);

    fclose(fp);

    return ret;
}

float * read_positions(char * file) {

    FILE * fp = fopen(file, "r");

    // Check file can be read:
    assert(fp != NULL);

    // Read opening block size field for header
    // structure:
    int blocksize;
    fread(&blocksize, sizeof(int), 1, fp);

    // Skip the header structure:
    fseek(fp, blocksize, SEEK_CUR);

    // Read closing block size field for header
    // structure:
    fread(&blocksize, sizeof(int), 1, fp);

    // Read opening block size field for position
    // array:
    fread(&blocksize, sizeof(int), 1, fp);

    // Each particle requires 3 floats (x,y,z) which has
    // size 4 * 3 = 12 bytes:
    int num_particles = blocksize / 12;

    // Read in position array:
    float * ret = calloc(3 * num_particles, sizeof(float));
    assert(ret != NULL);
    fread(ret, sizeof(float), 3 * num_particles, fp);

    fclose(fp);

    return ret;
}

float * read_velocities(char * file) {

    FILE * fp = fopen(file, "r");

    // Check file can be read:
    assert(fp != NULL);

    // Read opening block size field for header
    // structure:
    int blocksize;
    fread(&blocksize, sizeof(int), 1, fp);

    // Skip the header structure:
    fseek(fp, blocksize, SEEK_CUR);

    // Read closing block size field for header
    // structure:
    fread(&blocksize, sizeof(int), 1, fp);

    // Read opening block size field for position
    // array:
    fread(&blocksize, sizeof(int), 1, fp);

    // Skip the position array:
    fseek(fp, blocksize, SEEK_CUR);

    // Read closing block size field for position
    // array:
    fread(&blocksize, sizeof(int), 1, fp);

    // Read opening block size field for velocity
    // array:
    fread(&blocksize, sizeof(int), 1, fp);

    // Each particle requires 3 floats (x,y,z) which has
    // size 4 * 3 = 12 bytes:
    int num_particles = blocksize / 12;

    // Read in velocity array:
    float * ret = calloc(3 * num_particles, sizeof(float));
    assert(ret != NULL);
    fread(ret, sizeof(float), 3 * num_particles, fp);

    fclose(fp);

    return ret;
}

void header_show_details(Header h) {

    printf("Total number of particles: %d\n", header_get_n_particles(h));
    printf("Box size: %f\n", header_get_boxsize(h));
    printf("Snapshot taken at time: %f\n", header_get_time(h));
    printf("Snapshot taken at redshift: %f\n", header_get_redshift(h));
    printf("Total matter density at today (Omega0): %f\n", header_get_matter_density(h));
    printf("Dark energy density at today (OmegaLambda): %f\n", header_get_dark_matter_density(h));
}

int header_get_n_particles(Header h) {

    int ret = 0;
    for (int i = 0; i < N_PARTICLE_TYPES; i++) ret += h.npart[i];
    return ret;
}

double header_get_time(Header h) {
    return h.time;
}

double header_get_redshift(Header h) {
    return h.redshift;
}

double header_get_boxsize(Header h) {
    return h.BoxSize;
}

double header_get_matter_density(Header h) {
    return h.Omega0;
}

double header_get_dark_matter_density(Header h) {
    return h.OmegaLambda;
}

