import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  {
    path: 'home',
    loadChildren: () => import('./home/home.module').then( m => m.HomePageModule)
  },
  {
    path: '',
    redirectTo: 'home',
    pathMatch: 'full'
  },
  {
    path: 'single-appareil',
    loadChildren: () => import('./appareils/single-appareil/single-appareil.module').then( m => m.SingleAppareilPageModule)
  },
  {
    path: 'appareil',
    loadChildren: () => import('./appareil/appareil.module').then( m => m.AppareilPageModule)
  },
  {
    path: 'appareils',
    loadChildren: () => import('./appareils/appareils.module').then( m => m.AppareilsPageModule)
  },
  {
    path: 'settings',
    loadChildren: () => import('./settings/settings.module').then( m => m.SettingsPageModule)
  },
  {
    path: 'tabs',
    loadChildren: () => import('./tabs/tabs.module').then( m => m.TabsPageModule)
  },

];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
