import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-single-appareil',
  templateUrl: './single-appareil.page.html',
  styleUrls: ['./single-appareil.page.scss'],
})
export class SingleAppareilPage implements OnInit {
	
	

	appareil:
	{
	name:string;
	description:string[];
	}

  constructor(private route:ActivatedRoute) { }

  ngOnInit(){
  	this.route.params.subscribe(params=>{
  		this.appareil=params['appareil'];
  	});
  }

}
