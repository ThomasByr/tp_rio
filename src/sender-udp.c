# include ...

int main{int argc, char **argv)
{
  int sockfd;                      // descripteur de socket
  struct sockaddr_in dest;         // structure d'adresse qui contiendra les
                                   // parametres reseaux du destinataire

  // verification du nombre d'arguments sur la ligne de commande
  if(argc != 4)
    {
      printf("Usage : %s @dest num_port chaine_a_envoyer\n", argv[0]);
      exit(-1);
    }

  // creation de la socket
  sockfd = socket(...);

  // initialisation de la structure d'adresse du destinataire :

  // famille d'adresse
  dest.sin_family = ...;

  // adresse IPv4 du destinataire
  inet_aton(... , &(dest.sin.addr));

  // port du destinataire
  dest.sin_port = ...;

  // envoi de la chaine
  if(sendto(...) == -1)
    {
      perror("erreur a l'appel de la fonction sendto -> ");
      exit(-2);
    }

  // fermeture de la socket
  close(...);

  return 0;
}
