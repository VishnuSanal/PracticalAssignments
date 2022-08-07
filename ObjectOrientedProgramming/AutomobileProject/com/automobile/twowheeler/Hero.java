package com.automobile.twowheeler;

import com.automobile.Vehicle;

public class Hero extends Vehicle{

	public String getModelName(){
		return "Hero model name";
	}
	public String getRegisterName(){
		return "Hero register number";
	}
	public String getOwnerName(){
		return "Hero owner name";
	}
	
	public int getSpeed(){
		return 240;
	}
	
	public void radio(){
		System.out.println("Hero operating radio");
	}

}
