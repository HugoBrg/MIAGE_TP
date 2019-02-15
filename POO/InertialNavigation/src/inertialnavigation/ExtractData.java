package inertialnavigation;

import java.awt.Graphics;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author hugob
 */
public class ExtractData {
    public DataStruct[] dataCSV = new DataStruct[1399];
    public ExtractData() throws FileNotFoundException, IOException {
        BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\hugob\\Google Drive\\MIAGE\\Cours\\Programmation orientée objet & Génie logiciel\\InertialNavigation\\src\\inertialnavigation\\capture.csv"));
        String line = null;
        Scanner scanner = null;
        int i = 0;
        int w = 0;
	while ((line = reader.readLine()) != null) {
            scanner = new Scanner(line);
            scanner.useDelimiter(";");
            dataCSV[w]=new DataStruct();
            while (scanner.hasNext()) {
                String data = scanner.next();
                System.out.println(data);
                switch (i) {
                    case 0:
                        //System.out.println(data);
                        data = data.replaceAll("[^0-9]+", "");
                        dataCSV[w].id=Integer.parseUnsignedInt(data);
                        //dataCSV[w].id=Double.parseDouble(data);
                        break;
                    case 1:
                        dataCSV[w].time=Double.parseDouble(data);
                        break;
                    case 2:
                        dataCSV[w].x=Double.parseDouble(data);
                        break;
                    case 3:
                        dataCSV[w].y=Double.parseDouble(data);
                        break;
                    case 4 :
                        dataCSV[w].z=Double.parseDouble(data);
                        break;
                    default:
                        //System.out.println("invalid data::" + data);
                        break;
                }
                i++;
                //System.out.println(dataCSV[w].id);
            }
            w++;
            i = 0;
	}
        TraceurCourbes tc = new TraceurCourbes(dataCSV);
	reader.close();
    }  
}
