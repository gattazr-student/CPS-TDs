#include <stdio.h>
#include <math.h>

typedef struct t_point_cart {
    double x; /* coordonnée en x */
    double y; /* coordonnée en y */
}point_cart;

typedef struct t_point_pol {
    double theta; /* angle */
    double rho; /* distance */
}point_pol;

typedef point_cart (*t_fct_rt_vers_cart)(point_pol); /* pointeur sur fonction */

/**
 * create
 * Crée un point polaire à partir de ses coordonnées polaire
 * @param aRho rho du point
 * @param aTheta theta du piont
 * @return point_pol situé aux coordonnées donnée en paramètres
 */
point_pol create(double aRho, double aTheta){
	point_pol wPointPol;
	wPointPol.rho = aRho;
	wPointPol.theta = aTheta;

	return wPointPol;
}

/**
 * fct_rt_vers_xy
 * Crée un point cartésien correspondant au point polaire donnée en paramètre
 * @param aPointPol point polaire
 * @return point_cart situé au même endroit que le point polaire passé en paramètre
 */
point_cart fct_rt_vers_xy(point_pol aPointPol){
	point_cart wPointCart;

	wPointCart.x = aPointPol.rho * cos(aPointPol.theta*M_PI/180);
	wPointCart.y = aPointPol.rho * sin(aPointPol.theta*M_PI/180);

	return wPointCart;
}

/**
 * proc_rt_vers_xy
 * modifie le point cartésien passé en paramètre par pointeur et le place aux coordonnées du point polaire
 * passé en paramètre
 * @param aPointPol point polaire
 * @param *aPointCart pointeur sur un point cartésien
 * @return point_cart situé au même endroit que les le point polaire passé en paramètre
 */
void proc_rt_vers_xy(point_pol aPointPol, point_cart* aPointCart){
	aPointCart->x = aPointPol.rho * cos(aPointPol.theta*M_PI/180);
	(*aPointCart).y = aPointPol.rho * sin(aPointPol.theta*M_PI/180);
}

/**
 * fct_rt_vers_negXY
 * Crée un point cartésien correspondant au point polaire donnée en paramètre avec un angle de 180-theta.
 * @param aPointPol point polaire
 * @return point_cart situé au même endroit que les le point pass en paramètre
 */
point_cart fct_rt_vers_negXY(point_pol aPointPol){
	aPointPol.theta = 180 - aPointPol.theta;
	return fct_rt_vers_xy(aPointPol);
}

/**
 * fct_rt_vers_XnegY
 * Crée un point cartésien correspondant au point polaire donnée en paramètre avec un angle de 180-theta.
 * @param aPointPol point polaire
 * @return point_cart situé au même endroit que les le point pass en paramètre
 */
point_cart fct_rt_vers_XnegY(point_pol aPointPol){
	aPointPol.theta = 360 - aPointPol.theta;
	return fct_rt_vers_xy(aPointPol);
}

/**
 * fct_rt_vers_negXnegY
 * Crée un point cartésien correspondant au point polaire donnée en paramètre avec un angle de 180+theta.
 * @param aPointPol point polaire
 * @return point_cart situé au même endroit que les le point pass en paramètre
 */
point_cart fct_rt_vers_negXnegY(point_pol aPointPol){
	aPointPol.theta = 180 + aPointPol.theta;
	return fct_rt_vers_xy(aPointPol);
}


point_cart fct_rt_vers_cart(point_pol aPointPol, t_fct_rt_vers_cart aFunction) {
	return aFunction(aPointPol);
}

/**
 * main
 * Fonction de test
 */
int main(void){
    point_pol wPPol;
    point_cart wPCart;
    double wRho, wTheta;

    /* Récupération d'un Rho et d'un Theta pour créer un point polaire */
    printf("Saisir coordonnees polaires : ");
    scanf("%lf %lf", &wRho, &wTheta);
    wPPol = create(wRho, wTheta);

    /* Utilisation d'une procédure */
    proc_rt_vers_xy(wPPol, &wPCart);
    printf("Voici le point cart. correspondant :\n");
    printf("\tx = %f, \ty = %f\n", wPCart.x, wPCart.y);

    /* Utilisation d'un pointeur sur fonction  */
    wPCart = fct_rt_vers_cart(wPPol, &fct_rt_vers_negXY);
    printf("Rotation pour avoir x négatif :\n");
    printf("\tx = %f, \ty = %f\n", wPCart.x, wPCart.y);

    /* Utilisation d'un pointeur sur fonction  */
    wPCart = fct_rt_vers_cart(wPPol, &fct_rt_vers_XnegY);
    printf("Rotation pour avoir y négatif :\n");
    printf("\tx = %f, \ty = %f\n", wPCart.x, wPCart.y);

    /* Utilisation d'un pointeur sur fonction  */
    wPCart = fct_rt_vers_cart(wPPol, &fct_rt_vers_negXnegY);
    printf("Rotation pour avoir x et y négatifs :\n");
    printf("\tx = %f, \ty = %f\n", wPCart.x, wPCart.y);

    return 0;
}
