#include ...

int main(int argc, char **argv)
{
  int sockfd;                   // descripteur de socket
  char buf[1024];               // espace necessaire pour stocker le message recu

  // taille d'une structure sockaddr_in utile pour la fonction recvfrom
  socklen_t fromlen = sizeof(struct sockaddr_in); 

  struct sockaddr_in my_addr;   // structure d'adresse qui contiendra les param reseaux du recepteur
  struct sockaddr_in client;    // structure d'adresse qui contiendra les param reseaux de l'expediteur

  // verification du nombre d'arguments sur la ligne de commande
  if(argc != 2)
    {
      printf("Usage: %s port_local\n", argv[0]);
      exit(-1);
    }

  // creation de la socket
  sockfd = socket(...);

  // initialisation de la structure d'adresse du recepteur (pg local)

  // famille d'adresse
  my_addr.sin_family = ...;

  // recuperation du port du recepteur
  my_addr.sin_port = ;

  // adresse IPv4 du recepteur
  inet_aton(..., &(my_addr.sin_addr));

  // association de la socket et des param reseaux du recepteur
  if(bind(...) != 0)
    {
      perror("erreur lors de l'appel a bind -> ");
      exit(-2);
    }

  // reception de la chaine de caracteres
  if(recvfrom(..., &fromlen) == -1)
    {
      perror("erreur de reception -> ");
      exit(-3);
    }

  // affichage de la chaine de caracteres recue
  printf(...);

  // fermeture de la socket
  close(...);

  return 0;
}
