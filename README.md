# Ajusteur-hauteur-d-cran-Arduino-Python

Ces  codes ont pour but d'ajuster la hauteur d'un écran automatiquement via une carte arduino,  moteur et une petite caméra.

La caméra (OpenMv cam H7) se programme en python. Elle permet de faire la détection des iris et, après les avoirs détecté,
d'envoyer l'information à la carte arduino sous la forme d'une tention.

Lorsque la carte arduino détecte une tension provenant du pin de la caméra relier à elle même, elle stop alors le moteur car cela signifie que
le haut de l'écran est à la hauteur des yeux.

Tout le système se lance à partir d'un petit bouton poussoir, lorsque l'on appuie sur le bouton, la détection des iris se lance, et le moteur commence
à faire monter l'écran et ne se stopera qu'une fois les iris de l'utilisateur détecté.

2 LED permettent de savoir lorsque le moniteur est prêt à l'emplois ou non. Lorsque qu'il n'est pas prêt, une LED rouge esr allumée et dès qu'il est prêt une LED 
verte s'allume.

Une base de donnée permet également de faire la sauvegarde du "profil" de hauteur de l'utilisateur avec une reconaissance par badge RFID.

Le système fonctionne et à été testé en condition réelle. En revanche la base de donnée ne fonctionne pas.
