import { Component, OnInit } from '@angular/core';
import {Router}    from '@angular/router';
import {SingleAppareilPage} from './single-appareil/single-appareil.page';

@Component({
  selector: 'app-appareils',
  templateUrl: './appareils.page.html',
  styleUrls: ['./appareils.page.scss'],
})
export class AppareilsPage implements OnInit {




  appareilsList = [
    {
      name: 'Machine à laver',
      description: [
        'Volume: 6 litres',
        'Temps de lavage: 2 heures',
        'Consommation: 173 kWh/an'
      ]
    },
    {
      name: 'Télévision',
      description: [
        'Dimensions: 40 pouces',
        'Consommation: 22 kWh/an'
      ]
    },
    {
      name: 'Ordinateur',
      description: [
        'Marque: fait maison',
        'Consommation: 500 kWh/an'
      ]
    }
  ];
  constructor(private router:Router) { }

  ngOnInit() {
  }


  onLoadAppareil(appareil:{name:string,description:string []}){
  this.router.navigate(['/single-appareil',{appareil:appareil}]);
  }

}
