import { Component, OnInit,OnDestroy } from '@angular/core';
import { Observable } from 'rxjs/Observable';
import 'rxjs/add/observable/interval';
import { Subscription } from 'rxjs/Subscription';
import * as firebase from 'firebase';


@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {

  secondes: number;
  counterSubscription: Subscription;

  ngOnInit() {
    const counter = Observable.interval(1000);
    this.counterSubscription = counter.subscribe(
      (value) => {
        this.secondes = value;
      },
      (error) => {
        console.log('Uh-oh, an error occurred! : ' + error);
      },
      () => {
        console.log('Observable complete!');
      }
    );
  }

  ngOnDestroy() {
    this.counterSubscription.unsubscribe();
  }

    const config = {
      apiKey: 'AIzaSyCwfa_fKNCVrDMR1E88S79mpQP-6qertew4',
      authDomain: 'bookshelves-3d570.firebaseapp.com',
      databaseURL: 'https://bookshelves-3d570.firebaseio.com',
      projectId: 'bookshelves-3d570',
      storageBucket: 'bookshelves-3d570.appspot.com',
      messagingSenderId: '6634573823'
    };
    firebase.initializeApp(config);
  }
}
