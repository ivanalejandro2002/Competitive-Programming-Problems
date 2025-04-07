import java.util.*;
class Main
{

    public static void main(String[] args)
    {                 
        Curps curps = new Curps();
        int n = Integer.valueOf(args[0]);
         
        for(int i = 0; i < n; i++) {
            String nueva = curps.getCURP();
            System.out.println("Ingresando la nueva Curp = "+nueva);
            curps.ingresaEnOrden(nueva);
            System.out.println(curps);
        }
        
    }
           
}