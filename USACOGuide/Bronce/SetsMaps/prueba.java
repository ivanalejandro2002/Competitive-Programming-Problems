import java.util.Scanner;

class Prueba{
    public static void main(String[] args){
        Prueba obj = new Prueba();
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        String sizeer = scan.nextLine();
        while(t > 0){
            String size = scan.nextLine();
            String cad[] = size.split(" ");
            String resul = "";
            int a = obj.f(cad[0]);
            int b = obj.f(cad[1]);
            if(a > b) resul = ">";
            if(a < b) resul = "<";
            if(a == b) resul = "=";
            System.out.println(resul);
            t--;
        }
    }
    
    public int f(String cad){
        char c = cad.charAt(cad.length()-1);
        if(c == 'L'){
            return cad.length();
        }else if(c == 'M'){
            return 0;
        }else{
            return cad.length() * -1;
        }
    }
}