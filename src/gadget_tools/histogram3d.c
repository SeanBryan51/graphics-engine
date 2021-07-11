#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "reader.h"

#define N_PIXELS 800
#define PIXEL_SIZE (256.0 / N_PIXELS)

int main() {

    printf("Allocating histogram memory...\n");
    int * histogram = calloc(N_PIXELS * N_PIXELS * N_PIXELS, sizeof(int));

    Header header = read_header("snapshot_003");
    header_show_details(header);

    float * positions = read_positions("snapshot_003");

    printf("Computing histogram...\n");

    int n_particles = header_get_n_particles(header);
    for (int index = 0; index < 3 * n_particles; index += 3) {

        float x = positions[index];
        float y = positions[index + 1];
        float z = positions[index + 2];

        int pixel_x = floor(x / PIXEL_SIZE * 1.0f);
        int pixel_y = floor(y / PIXEL_SIZE * 1.0f);
        int pixel_z = floor(z / PIXEL_SIZE * 1.0f);

        histogram[pixel_x + N_PIXELS * (pixel_y + N_PIXELS * pixel_z)] += 1;
    }

    printf("Done.\n");

    printf("Writing histogram to histogram3d.out\n");
    FILE * fp = fopen("histogram3d.out", "w");

    fwrite(histogram, sizeof(int), N_PIXELS * N_PIXELS * N_PIXELS, fp);

    fclose(fp);

    printf("Freeing histogram...\n");
    free(histogram);

    return EXIT_SUCCESS;
}

