import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
import {Observable} from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AppiService {

  constructor(private http:HttpClient) { }
  baseurl="http://127.0.0.1:8000";
  httpHeaders=new HttpHeaders({  
    'Content-Type':  'application/json',
    'Access-Control-Allow-Credentials' : 'true',
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET, POST, PATCH, DELETE, PUT, OPTIONS',
    'Access-Control-Allow-Headers': 'Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With',
});



  getAllMovies():Observable<any>{
    return this.http.get(this.baseurl +'/movies' ,{headers:this.httpHeaders});
  }
}
