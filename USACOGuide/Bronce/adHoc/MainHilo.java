import java.util.*;
class MainHilo
{

    public static void main(String[] args) 
    {    
        Hilito hilos = new Hilito();
        int n = Integer.valueOf(args[0]);

        System.out.println("Main thread is: "
                           + Thread.currentThread().getName());
      
          // Creating Thread
        hilos.ejecuta(n);
        System.out.print("Variable compartida terminó con un valor de: ");
        System.out.println(hilos.show());
    }
           
}