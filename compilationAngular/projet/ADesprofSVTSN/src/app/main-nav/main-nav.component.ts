import { Component,OnInit, Input } from '@angular/core';
import { BreakpointObserver, Breakpoints } from '@angular/cdk/layout';
import { Observable } from 'rxjs';
import { map, shareReplay } from 'rxjs/operators';
import {MatGridListModule} from '@angular/material/grid-list';

export interface Tile {
	color: string;
	cols: number;
	rows: number;
	text: string;
  }
@Component({
  selector: 'app-main-nav',
  templateUrl: './main-nav.component.html',
  styleUrls: ['./main-nav.component.css']
})
export class MainNavComponent implements OnInit {
   
	isAuth:boolean;
	changeText: boolean;//inachever
	isHome:boolean;
	isInitiative:boolean
	isActivite:boolean;
	isTest:boolean;
	isPremierevisite:boolean;



  isHandset$: Observable<boolean> = this.breakpointObserver.observe(Breakpoints.Handset)
    .pipe(
      map(result => result.matches),
      shareReplay()
    );

  constructor(private breakpointObserver: BreakpointObserver){
	  
  }
  tiles: Tile[] = [
    {text: 'One', cols: 3, rows: 1, color: 'lightblue'},
    {text: 'Two', cols: 1, rows: 2, color: 'lightgreen'},
    {text: 'Three', cols: 1, rows: 1, color: 'lightpink'},
    {text: 'Four', cols: 2, rows: 1, color: '#DDBDF1'},
  ];
	
  

  ngOnInit(){
	
	this.isHome=true;
	this.isAuth=false;
	this.isPremierevisite=false;
	this.isInitiative=false;
	this.isTest=false;
	this.isActivite=false;
  }


  Onclik(id :number){

	switch (id) {
		case 1:this.isHome=true;
		this.isPremierevisite=false;
		this.isInitiative=false;
		this.isTest=false;
		this.isActivite=false;
		console.log(id);
			break;
		case 2:
		this.isHome=false;
		this.isPremierevisite=false;
		this.isTest=false;
		this.isActivite=false;
		this.isInitiative=true;
			console.log(id);
			break;
		case 3:
			this.isHome=false;
			this.isPremierevisite=true;
			this.isInitiative=false;
			this.isTest=false;
			this.isActivite=false;
			console.log(id);
			break;
		case 4:
			this.isHome=false;
			this.isPremierevisite=false;
			this.isInitiative=false;
			this.isTest=true;
			this.isActivite=false;
			console.log(id);
			break;
			case 5:
				this.isHome=false;
				this.isPremierevisite=false;
				this.isInitiative=false;
				this.isTest=false;
				this.isActivite=true;
				console.log(id);
				break;
		
	}
  }
}
