import com.automobile.twowheeler.*;

public class Test{
	public static void main(String[] args){
		
		Hero hero = new Hero();
		Honda honda = new Honda();
		
		P(hero.getModelName());
		P(hero.getRegisterName());
		P(hero.getOwnerName());
		P(hero.getSpeed());
		hero.radio();
		
		P(honda.getModelName());
		P(honda.getRegisterName());
		P(honda.getOwnerName());
		P(honda.getSpeed());
		honda.cdPlayer();
		
	}
	
	static void P(String s){
		System.out.println(s);
	}
	
	static void P(int s){
		System.out.println(s);
	}
	
}
