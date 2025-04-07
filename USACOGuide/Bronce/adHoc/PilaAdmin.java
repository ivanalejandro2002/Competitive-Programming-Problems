import java.util.*;
class Pila{
    private int tamano;
    private int maximo;
    private char[] datos;

    Pila(){
        datos = new char[10];
        tamano = 0;
        maximo = 10;
    }

    public void push(char v){
        if(tamano>=maximo)return;
        datos[tamano++] = v;
    }

    public void pop(){
        if(tamano<=0)return;
        tamano--;
    }


    @Override
    public String toString(){
        String s = "Los valores de la pila son:\n";
        for(int z:datos){
            s+= Integer.toString(z) + "->";
        }

        s = s.substring(0,s.length()-2);
        return s;
    }
}


public class PilaAdmin {

    public static void main(String[] args){

        Random aleatorio = new Random(System.currentTimeMillis());
        int tp = aleatorio.nextInt(2000)+1000;
        int tc = aleatorio.nextInt(2000)+1000;

        Thread hilo1 = new Thread(new Runnable() {
            @Override

            public void run(){
                try
                {
                    Thread.sleep(tp);
                }
                catch(InterruptedException ex)
                {
                    Thread.currentThread().interrupt();
                }
            }
        });

        Thread hilo2 = new Thread(new Runnable(){
            @Override
            public void run(){
                try
                {
                    Thread.sleep(tc);
                }
                catch(InterruptedException ex)
                {
                    Thread.currentThread().interrupt();
                }
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
    }
}