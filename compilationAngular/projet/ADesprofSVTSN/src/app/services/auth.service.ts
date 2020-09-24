import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http'
import { User } from '../models/user.model';
import { from } from 'rxjs';



@Injectable({
  providedIn: 'root'
})
export class AuthService {

  private loginUrl="http://localhost:8000/api-token-auth//login/"


  constructor(private http: HttpClient) {
  }
    
  login(email:string, password:string ) {
      return this.http.post<User>(this.loginUrl, {email, password})
          // this is just the HTTP call, 
          // we still need to handle the reception of the token
         //.shareReplay();
  }
}