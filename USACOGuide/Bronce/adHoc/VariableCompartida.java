public class VariableCompartida {
    static int v_comp = 0;
    public static void main(String[] args){
        int n =  Integer.parseInt(args[0]);
        System.out.println("n: " + n);
        Thread hilo1 = new Thread(new Runnable() {
            @Override
            public void run(){
                for (int i = 0; i < n; i++)
                    modifica(1);
            }
        });

        Thread hilo2 = new Thread(new Runnable(){
            @Override
            public void run(){
                for (int i = 0; i < n; i++)
                    modifica(2);
            }
        });

        hilo1.start();
        hilo2.start();


        try {
            hilo1.join();
            hilo2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.print("Variable compartida: " + v_comp);
    }

    public synchronized static void modifica(int id){

        if(id == 1) v_comp++;
        else v_comp--;
    }
}