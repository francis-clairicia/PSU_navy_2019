/*
** EPITECH PROJECT, 2019
** Square root
** File description:
** Found the square root of a number
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    int sq = 0;

    if (nb <= 0)
        return (0);
    while (my_compute_power_rec(sq, 2) < nb)
        sq += 1;
    if (my_compute_power_rec(sq, 2) == nb)
        return (sq);
    return (0);
}
