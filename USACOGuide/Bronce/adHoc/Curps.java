import java.util.*;
class Curps
{
    static int num = 3;
    List<String> curps = new ArrayList<>();

    public void ingresaEnOrden(String nuevo){

        Iterator<String> itr = curps.iterator();
        int idx = 0;
        while(itr.hasNext()){
            String s = itr.next();
            if(nuevo.compareTo(s.substring(0,4))<0){
                curps.add(idx,nuevo);
                return;
            }
            idx++;
        }
        curps.add(nuevo);
        
    }
    static String getCURP()
    {
        String Letra = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String Numero = "0123456789";
        String Sexo = "HM";
        String Entidad[] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};
        int indice;
        
        StringBuilder sb = new StringBuilder(18);
        
        for (int i = 1; i < 5; i++) {
            indice = (int) (Letra.length()* Math.random());
            sb.append(Letra.charAt(indice));        
        }
        
        for (int i = 5; i < 11; i++) {
            indice = (int) (Numero.length()* Math.random());
            sb.append(Numero.charAt(indice));        
        }
        indice = (int) (Sexo.length()* Math.random());
        sb.append(Sexo.charAt(indice));        
        
        sb.append(Entidad[(int)(Math.random()*32)]);
        for (int i = 14; i < 17; i++) {
            indice = (int) (Letra.length()* Math.random());
            sb.append(Letra.charAt(indice));        
        }
        for (int i = 17; i < 19; i++) {
            indice = (int) (Numero.length()* Math.random());
            sb.append(Numero.charAt(indice));        
        }
        
        return sb.toString();
    }         
    @Override  
    public String toString(){
        String s = "Las curps actuales son:\n";
        for(String v:curps){
            s+="["+v+"],";
        }
        s+="\n";
        return s;
    }
}