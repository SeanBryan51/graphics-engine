#include <stdlib.h>
#include <stdio.h>

#include "reader.h"

int main() {

    Header header = read_header("snapshot_003");

    header_show_details(header);

    float * positions = read_positions("snapshot_003");
    float * velocities = read_velocities("snapshot_003");

    int index = 0;
    while (getchar() != EOF) {
        printf("index : %d", index);
        printf("[%f, %f, %f], ", positions[index], positions[index + 1], positions[index + 2]);
        printf("[%f, %f, %f]\n", velocities[index], velocities[index + 1], velocities[index + 2]);
        index += 3;
    }

    int n_particles = header_get_n_particles(header);
    printf("n_particles : %d\n", n_particles);

    printf("[%f, %f, %f], ", positions[n_particles - 1], positions[n_particles - 1 + 1], positions[n_particles - 1 + 2]);
    printf("[%f, %f, %f]\n", velocities[n_particles - 1], velocities[n_particles - 1 + 1], velocities[n_particles - 1 + 2]);

    return EXIT_SUCCESS;
}
