# coding: utf-8

import matplotlib.pyplot as plt
import numpy as np
import sys


if __name__ == "__main__" : # si le module est execute comme un main

    # count the arguments
    arguments = len(sys.argv) - 1   
    # output argument-wise
    if  (arguments == 0):  
        z_debut = 0
        z_fin = 200
    elif  (arguments != 2):  
        print ("Usage: python  %s  first_value  second_value ", sys.argv[0])
        sys.exit(2)
    else:
        z_debut = sys.argv[1]
        z_fin = sys.argv[2]

    #--- Chargement du fichier contenant les echantillons
    fn16 = "mel_samples.csv"
    y16 = np.loadtxt(fn16)

    fn4 = "mel_4b_samples.csv"
    y4 = np.loadtxt(fn4)
        
    #--- Erreur de quantification
    error = y16-y4
    
    #--- On va faire une figure 
    fig= plt.figure(figsize=(16,8)) 
    
    ax1 = fig.add_subplot(121) # La figure contient 2 subplots en
    # ligne car 12 => 1 ligne et 2 colonnes et ax1 est en colonne 1
    ax1.plot(y16, label="16 bits") # plot
    ax1.plot(y4, label="8 bits") # plot
    ax1.plot(error, label="error") # plot
    ax1.set_title("Une courbe")    

    ax2 = fig.add_subplot(122) # 2eme colonne de la figure
    ax2.plot(y16, "o-", label="16bits") # on modifie le marker de
    ax2.plot(y4, "o-", label="8bits") # on modifie le marker de
    ax2.plot(error, label="error") # plot

    # chaque sample et on se prepare a faire une legende

    # Configuration du subplot/axe
    ax2.set_xlim( (z_debut,z_fin) ) 
    ax2.set_title("zoom entre {} et  {}".format(z_debut, z_fin))
    
    ax2.grid(True)
    ax2.set_xlabel("n0")
    ax2.set_ylabel("y : Son")
    ax2.legend()

    # Affichage de la figure
    plt.show()
    
