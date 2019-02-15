# coding: utf-8

import matplotlib.pyplot as plt
import numpy as np
import sys
  

if __name__ == "__main__" : # si le module est execute comme un main

    # count the arguments
    arguments = len(sys.argv) - 1   
    # output argument-wise
    if  (arguments == 1):  
        z_debut = 0
        z_fin = 200
    elif  (arguments != 3):  
        print ("Usage: python  %s  filename first_value  second_value ", sys.argv[0])
        sys.exit(2)
    else:
        z_debut = sys.argv[2]
        z_fin = sys.argv[3]

    #--- Chargement du fichier contenant les echantillons
    fn = sys.argv[1]
    #fn = "samples.csv"
    y = np.loadtxt(fn)

    #--- On va faire une figure 
    fig= plt.figure(figsize=(16,8)) 
    
    ax1 = fig.add_subplot(121) # La figure contient 2 subplots en
    # ligne car 12 => 1 ligne et 2 colonnes et ax1 est en colonne 1
    ax1.plot(y, label="Sinusoide") # plot
    ax1.set_title("Une courbe")    

    ax2 = fig.add_subplot(122) # 2eme colonne de la figure
    ax2.plot(y, "o-", label="Sinusoide") # on modifie le marker de
    # chaque sample et on se prepare a faire une legende

    # Configuration du subplot/axe
    ax2.set_xlim( (z_debut,z_fin) ) 
    ax2.set_title("zoom entre {} et  {}".format(z_debut, z_fin))
    
    ax2.grid(True)
    ax2.set_xlabel("n0")
    ax2.set_ylabel("y : Sinus")
    ax2.legend()

    # Affichage de la figure
    plt.show()
    
