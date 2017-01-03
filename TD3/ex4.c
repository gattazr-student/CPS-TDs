#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

int main (int aArgc, char** aArgv){
	int wI; /* Variable de boucle sur les paramètres */
	char *wProgName = aArgv[0]; /* aArgv[0] existe toujours et contient le nom du programme */

	struct stat wFileInfo; /* Info sur le fichier courant si il existe pendant la boucle */
	char wPermissions[12];/* Tableau qui contiendra les permissions du fichier si il existe*/
	struct passwd* wUserInfo; /* Structure qui contiendra des informations sur un user */
	struct group* wGroupInfo; /* Structure qui contiendra des informations sur un group*/
	struct tm* wTimeInfo; /* Structure qui contiendra des informations sur une date */

	/* On vérifie qu'il il y a au moin un nom de fichier*/
	if(aArgc < 2){
		fprintf(stderr, "%s: un nom de fichier est attendu\n", wProgName);
		fprintf(stderr, "usage : %s fileName [FileName ...]\n", wProgName);
		return 1;
	}

	/* Les stats */
	for(wI = 1; wI < aArgc; wI++){
		/* On teste si le fichier existe */
		if(stat(aArgv[wI], &wFileInfo) != -1){
			/* Le fichier existe, écriture d'une ligne d'information sur le fichier */

			/* Le nom du fichier */
			fprintf(stdout, "  File: '%s'\n", aArgv[wI]);

			/* La taille du fichier, le nombre de blocks et leurs tailles */
			fprintf(stdout, "  Size: %lu\t\tBlocks: %lu\t\tIO Block: %d\t",
				(unsigned long)(wFileInfo.st_size),
				(unsigned long)(wFileInfo.st_blocks),
				(int)(wFileInfo.st_blksize));

			/* Détermine le type du fichier */
			if(S_ISREG(wFileInfo.st_mode)){
				fprintf(stdout, "regular file\n");
			}else if(S_ISDIR(wFileInfo.st_mode)){
				fprintf(stdout, "directory\n");
			}else if(S_ISCHR(wFileInfo.st_mode)){
				fprintf(stdout, "character device\n");
			}else if(S_ISBLK(wFileInfo.st_mode)){
				fprintf(stdout, "block device\n");
			}else if(S_ISFIFO(wFileInfo.st_mode)){
				fprintf(stdout, "FIFO\n");
			}else if(S_ISLNK(wFileInfo.st_mode)){
				fprintf(stdout, "symbolic link\n");
			}else if(S_ISSOCK(wFileInfo.st_mode)){
				fprintf(stdout, "socket\n");
			}

			/* L'identifiant du disque, l'inode du fichier et le nombre de lien matériel */
			fprintf(stdout, "Device: %d\tInode: %d\t\tLinks: %d\n",
				(int)(wFileInfo.st_dev),
				(int)(wFileInfo.st_ino),
				(int)(wFileInfo.st_nlink));

			/* Les Permissions du fichier */
			strmode(wFileInfo.st_mode, wPermissions);
			fprintf(stdout, "Access: (0%o/%s) ",
				wFileInfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO), wPermissions);
				/* ET logique avec les bits des permissions et on affiche la valeur en octal */

			/* Le propriétaire du fichier */
			fprintf(stdout, "Uid: (%d/", wFileInfo.st_uid);
			wUserInfo = getpwuid(wFileInfo.st_uid);
			if(wUserInfo != 0){
				fprintf(stdout, "%s", wUserInfo->pw_name);
			}
			fprintf(stdout, ")\t");


			/* Le groupe du propriétaire. Son gid si il n'est pas trouvé */
			fprintf(stdout, "Gid: (%d/", wFileInfo.st_gid);
			wGroupInfo = getgrgid(wFileInfo.st_gid);
			if(wGroupInfo != 0){
				fprintf(stdout, "%s", wGroupInfo->gr_name);
			}
			fprintf(stdout, ")\n");

			/* Date d'accès, de modification, et de changement de status */
			wTimeInfo = localtime(&wFileInfo.st_atime);
			fprintf(stdout, "Access: %s", asctime(wTimeInfo));
			wTimeInfo = localtime(&wFileInfo.st_mtime);
			fprintf(stdout, "Modify: %s", asctime(wTimeInfo));
			wTimeInfo = localtime(&wFileInfo.st_ctime);
			fprintf(stdout, "Change: %s", asctime(wTimeInfo));

		} else {
			/* Le fichier n'exite pas */
			fprintf(stderr, "%s: %s: No such file or directory\n", wProgName, aArgv[wI]);
		}
	}
	return 0;
}
