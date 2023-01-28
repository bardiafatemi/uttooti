#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
typedef struct user_id user;
typedef struct post post;
typedef struct like like;
struct user_id
{
    char *user_name;
    char *password;
    // post *post;
    user *next;
};
struct post
{
    char *user_name;
    int post_id;
    // like *like;
    char *text;
    post *next;
};
struct like
{
    char *username;
    like *next;
};
/*
int save_posts(post*head_post)
{
    post *post_temp = (post *)malloc(sizeof(post));
    post_temp = head_post;
    FILE* fp;
    fp = fopen("posts.txt", "w");
    if (fp != NULL)
    {
        while (1)
        {
            fprintf(fp, "%s %s\n", post_temp->next->text, post_temp->next->user_name);
            if (post_temp->next == NULL)
            {
                fclose(fp);
                return 0;
            }
            post_temp = post_temp->next;
            
        }
        
    }
}
int save_accounts(user*head)
{
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    FILE* fp;
    fp = fopen("accounts.txt", "w+");
    if (fp != NULL)
    {
        while (1)
        {
            printf("ss");
            // fprintf(fp, "%s %s\n", temp->next->user_name, temp->next->password);
            fputs(temp->next->user_name,fp);
            fputs(temp->next->password,fp);
            if (temp->next == NULL)
            {
                fclose(fp);
                return 0;
            }
            temp = temp->next;
            
        }
        
    }
}
*/
int delete_(user *head, post *head_post, char *current)
{
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    post *post_temp = (post *)malloc(sizeof(post));
    post_temp = head_post;
    int post_id;
    scanf("%d", &post_id);

    while (1)
    {
        if (post_temp->next->post_id == post_id && strcmp(post_temp->next->user_name, current) == 0)
        {
            post *prev = (post *)malloc(sizeof(post));
            prev = post_temp;
            prev->next = post_temp->next->next;
            free(post_temp->next);
            printf("post was deleted");
            //save_posts(head_post);
            return 1;
        }
        else if (post_temp->next->next == NULL)
        {
            printf("there is no post with this id");
            return 0;
        }
        post_temp = post_temp->next;
    }
}
// int like_counter(post*checked_post)
// {
//     post*post_temp=(post*)malloc(sizeof(post));
//     post_temp=checked_post;
//     int i=0;
//     while(1)
//     {
//         // like*like_temp=(like*)malloc(sizeof(like));
//         // like_temp->next=post_temp->like->next;
//         if(post_temp->like->next==NULL)
//         {
//             return i;
//         }
//         i++;
//         post_temp->like->next=post_temp->like->next->next;
//     }
// }
int info(user *head, post *head_post, char *current)
{
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    post *post_temp = (post *)malloc(sizeof(post));
    post_temp = head_post;
    while (1)
    {
        if (strcmp(temp->user_name, current) == 0)
        {
            printf("username: %s \n", temp->user_name);
            printf("password: %s \n", temp->password);

            while (1)
            {
                if (post_temp->next != NULL && strcmp(post_temp->next->user_name, current) == 0)
                {
                    printf("post_id: %d \n", post_temp->next->post_id);
                    // printf("num_of_likes: %d \n", );
                    printf("text: %s \n", post_temp->next->text);
                }
                else if (post_temp->next == NULL)
                {
                    return 0;
                }
                post_temp = post_temp->next;
            }
        }
        temp = temp->next;
    }
}
/*
int like_(user *head, char *current)
{
    char *user_name = (char *)malloc(21 * sizeof(char));
    int post_id;
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    scanf("%20s", user_name);
    scanf("%d", &post_id);
    while (1)
    {
        if (strcmp(temp->user_name, user_name) == 0)
        {
            while (1)
            {
                post*post_temp=(post*)malloc(sizeof(post));
                post_temp->next=temp->post->next;
                if (post_temp->next->post_id == post_id)
                {
                    while (1)
                    {


                        if (post_temp->next->like->next == NULL)
                        {
                            post_temp->next->like->next = (like *)malloc(sizeof(like));
                            post_temp->next->like->next->username = (char *)malloc(sizeof(char));
                            strcpy(post_temp->next->like->next->username, current);
                            post_temp->next->like->next->next=NULL;
                            printf("1");
                            return 1;
                        }
                        else if (strcmp(post_temp->next->like->next->username, current) == 0)
                        {
                            printf("you have already liked this post");
                            free(user_name);
                            return 0;
                        }
                        post_temp->next->like->next = post_temp->next->like->next->next;
                    }
                }
                else if (post_temp->next->next == NULL)
                {
                    printf("this post doesnt exist");
                    free(user_name);
                    return 0;
                }
                post_temp->next = post_temp->next->next;
            }
        }
        else if (temp->next == NULL)
        {
            printf("this user doesnt exist");
            free(user_name);
            return 0;
        }
        temp = temp->next;
    }
}
*/
int find_user(user *head, post *head_post, char *current)
{
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    post *post_temp = (post *)malloc(sizeof(post));
    post_temp = head_post;
    char *user_name = (char *)malloc(21 * sizeof(char));
    scanf("%20s", user_name);
    while (1)
    {
        if (strcmp(temp->user_name, user_name) == 0)
        {
            printf("username: %s \n", temp->user_name);

            while (1)
            {
                if (post_temp->next != NULL && strcmp(post_temp->next->user_name, user_name) == 0)
                {
                    printf("post_id: %d \n", post_temp->next->post_id);
                    // printf("num_of_likes: %d \n", );
                    printf("text: %s \n", post_temp->next->text);
                }
                else if (post_temp->next == NULL)
                {
                    free(user_name);
                    return 0;
                }
                post_temp = post_temp->next;
            }
        }
        temp = temp->next;
    }
}
int post_(user *head, post *head_post, char *current, int *last_post_id)
{
    post *post_temp = (post *)malloc(sizeof(post));
    post_temp = head_post;
    char *text = (char *)malloc(100 * sizeof(char));
    gets(text);

    while (1)
    {
        if (post_temp->next == NULL)
        {
            last_post_id[0]++;
            post_temp->next = (post *)malloc(sizeof(post));
            post_temp->next->text = (char *)malloc(100 * sizeof(char));
            post_temp->next->user_name = (char *)malloc(100 * sizeof(char));
            // post->next->like = (like *)malloc(sizeof(like));
            // temp->post->next->like->username = "-1";
            // post->next->like->next = NULL;
            strcpy(post_temp->next->user_name, current);
            strcpy(post_temp->next->text, text);
            free(text);
            post_temp->next->post_id = last_post_id[0];
            printf("post saved successfully with the id:%d", post_temp->next->post_id);
            post_temp->next->next = NULL;
            //save_posts(head_post);
            return 1;
        }
        post_temp = post_temp->next;
    }
}
int signup(user *head)
{
    char *user_name = (char *)malloc(21 * sizeof(char));
    char *password = (char *)malloc(21 * sizeof(char));
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    scanf("%20s", user_name);
    scanf("%20s", password);
    // printf("%s  %s",user_name,password);
    if (strcmp("login", user_name) == 0)
    {
        printf("this username cant be chosen");
        free(user_name);
        free(password);
        return 0;
    }
    if (strcmp("signup", user_name) == 0)
    {
        printf("this username cant be chosen");
        free(user_name);
        free(password);
        return 0;
    }
    while (1)
    {
        if (strcmp(temp->user_name, user_name) == 0)
        {

            printf("this username already exist");
            free(user_name);
            free(password);
            return 0;
        }

        else if (temp->next == NULL)
        {
            user *new_user = (user *)malloc(sizeof(user));
            new_user->user_name = (char *)malloc(20 * sizeof(char));
            new_user->password = (char *)malloc(20 * sizeof(char));
            temp->next = new_user;
            strcpy(new_user->user_name, user_name);
            strcpy(new_user->password, password);
            printf("signup successful");
            free(user_name);
            free(password);
            new_user->next = NULL;
            //save_accounts(head);
            return 1;
        }
        temp = temp->next;
    }
}
int login(user *head, char *current)
{
    char *user_name = (char *)malloc(21 * sizeof(char));
    char *password = (char *)malloc(21 * sizeof(char));
    user *temp = (user *)malloc(sizeof(user));
    temp = head;
    scanf("%20s", user_name);
    scanf("%20s", password);
    while (1)
    {
        if (strcmp(temp->user_name, user_name) == 0)
        {
            if (strcmp(temp->password, password) == 0)
            {
                printf("login successsful ");
                strcpy(current, temp->user_name);
                free(user_name);
                free(password);
                return 1;
            }
            else if (strcmp(temp->password, password) != 0)
            {
                printf("password is incoorect ");
                free(user_name);
                free(password);
                return 0;
            }
        }
        else if (temp->next == NULL)
        {
            printf("this user doesnt exist");
            free(user_name);
            free(password);
            return 0;
        }
        temp = temp->next;
    }
}
