import { BrowserModule } from '@angular/platform-browser';
import { NgModule} from '@angular/core';
import {HttpClientModule} from '@angular/common/http';

import { AppComponent } from './app.component';
import { MonPremierComponent } from './mon-premier/mon-premier.component';
import { AppareilComponent } from './appareil/appareil.component';
import {FormsModule} from '@angular/forms';
import {AuthGuard}  from './services/auth-guard.service';
import {AppareilService} from './services/appareil.service';
import {AuthService}   from './services/auth.service';
import {UserService}  from './services/user.service';
import {AuthComponent } from './auth/auth.component';
import {SingleAppareilComponent} from './single-appareil/single-appareil.component'
import {AppareilViewComponent } from './appareil-view/appareil-view.component';
import {Routes} from '@angular/router';
import {RouterModule} from '@angular/router';
import {EditAppareilComponent } from './edit-appareil/edit-appareil.component';
import {UserListComponent } from './user-list/user-list.component';
import {ReactiveFormsModule} from '@angular/forms';
import {NewUserComponent } from './new-user/new-user.component';

const appRoutes:Routes=[
   {path:'appareils',canActivate:[AuthGuard],component:AppareilViewComponent},
   {path:'appareils/:id',canActivate:[AuthGuard],component:SingleAppareilComponent},
   {path:'auth',component:AuthComponent},
   {path:'users',component:UserListComponent},
   {path:'',component:AppareilViewComponent},
   {path:'edit',canActivate:[AuthGuard],component:EditAppareilComponent},
   {path: 'users', component: UserListComponent },
   {path: 'new-user', component: NewUserComponent },

  ];

@NgModule({
  declarations: [
    AppComponent,
    MonPremierComponent,
    AppareilComponent,
    AuthComponent,
    AppareilViewComponent,
    EditAppareilComponent,
    UserListComponent,
    NewUserComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    ReactiveFormsModule,
    HttpClientModule,
    RouterModule.forRoot(appRoutes)
  ],
  providers: [
    AppareilService,
    AuthService,
    AuthGuard,
    UserService

    ],
  bootstrap: [AppComponent]
})
export class AppModule { }
