// Runnable Interface Implementation
public class Hilito
{
    static int variable_compartida = 0;
    public static void modifica(){
        String id = Thread.currentThread().getName();
        if(id == "hilo1")
                variable_compartida++;
        if(id == "hilo2")
                variable_compartida--;           
    }
    private class RunnableImpl implements Runnable 
    {
          // Overriding the run Method
          @Override
        public void run()
        {
            System.out.println(Thread.currentThread().getName()
                             + ", executing run() method!");
            modifica();
        }
    }  
  
      // Main Method

    public void ejecuta(int n){
        RunnableImpl proceso = new RunnableImpl();
        Thread t1 = new Thread(proceso, "hilo1");
        Thread t2 = new Thread(proceso, "hilo2");
        
        for(int i=0;i<n;i++){
          // Executing the Thread
          t1.start();
          t2.start();
        }
    }

    public int show(){
      return variable_compartida;
    }
}
