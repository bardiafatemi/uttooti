#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include"functions.h"

int main()
{
    int logged_in = 0; // 1 if a user has already logged in 0 if not
    user *head = (user *)malloc(sizeof(user));
    head->password = "-1";
    head->user_name = "-1";
    head->next = NULL;
    post *head_post = (post *)malloc(sizeof(post));
    head_post->text = "-1";
    head_post->user_name = "-1";
    head_post->next = NULL;
    char *current = (char *)malloc(20 * sizeof(char));
    int last_post_id;
    last_post_id = 0;
    while (1)
    {
        char *command = (char *)malloc(11 * sizeof(char));
        printf("\n");
        scanf("%10s", command);

        if (strcmp(command, "signup") == 0 && logged_in == 0) // singn up
        {
            free(command);
            signup(head);
        }

        else if (strcmp(command, "signup") == 0 && logged_in == 1) // shouldnt sign up
        {
            free(command);
            printf("you must logout first");
        }

        else if (strcmp(command, "login") == 0 && logged_in == 0) // login
        {
            free(command);
            if (login(head, current))
            {
                logged_in = 1;
            }
        }

        else if (strcmp(command, "login") == 0 && logged_in == 1) // shouldnt login
        {
            free(command);
            printf("you must logout first");
        }

        else if (strcmp(command, "post") == 0 && logged_in == 1) // post
        {
            free(command);
            post_(head, head_post, current, &last_post_id);
        }

        else if (strcmp(command, "post") == 0 && logged_in == 0) // shouldnt post
        {
            free(command);
            printf("you must loggin first");
        }
        /*
            else if (strcmp(command, "like") == 0 && logged_in == 1) // like
            {
                free(command);
                like_(head, current);
            }

            else if (strcmp(command, "like") == 0 && logged_in == 0) // shouldnt like
            {
                free(command);
                printf("you must loggin first");
            }
        */
        else if (strcmp(command, "logout") == 0 && logged_in == 1) // logout
        {
            free(command);
            logged_in = 0;
        }

        else if (strcmp(command, "logout") == 0 && logged_in == 0) // shouldnt logout
        {
            free(command);
            printf("you must loggin first");
        }

        else if (strcmp(command, "info") == 0 && logged_in == 1) // info
        {
            free(command);
            info(head, head_post, current);
        }

        else if (strcmp(command, "info") == 0 && logged_in == 0) // shouldnt info
        {
            free(command);
            printf("you must loggin first");
        }

        else if (strcmp(command, "find_user") == 0 && logged_in == 1) // info
        {
            free(command);
            find_user(head, head_post, current);
        }

        else if (strcmp(command, "find_user") == 0 && logged_in == 0) // shouldnt info
        {
            free(command);
            printf("you must loggin first");
        }

        else if (strcmp(command, "delete") == 0 && logged_in == 1) // delete
        {
            free(command);
            delete_(head, head_post, current);
        }

        else if (strcmp(command, "delete") == 0 && logged_in == 0) // shouldnt delete
        {
            free(command);
            printf("you must loggin first");
        }

        else if (strcmp(command, "exit") == 0) // for exiting software
        {
            break;
        }
        else
        {
            printf("this command doesnt exist");
        }
    }
    return 0;
}