//Project Euler Problem 1

int multiple_of_three_or_five (int number)
{
    if (((number % 3) && (number % 5)) == 0)
        return 1;
    else
        return 0;
}


int PE1main()
{
    int total = 0, index = 1, condition = 0;

    printf("Running Project Euler Problem 1\n");
    for (index = 1; index < 1000; index++)
        {
            condition = multiple_of_three_or_five (index);

            if (condition == 1)
                total = total + index;
        }

    printf ("Total: %i\n", total);
    return 0;
}
