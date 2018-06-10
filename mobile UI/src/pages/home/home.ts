import { Component, ViewChild } from '@angular/core';
import { NavController, AlertController, NavParams } from 'ionic-angular';
import { RegisterPage } from '../register/register'
import { TabsPage } from '../tabs/tabs'

@IonicPage()
@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {
  registerCredentials = { email: '', password: '' };

  constructor(public navCtrl: NavController, public navParams: NavParams) {
  }

  @ViewChild('username') user;
  @ViewChild('password') password;

  login() {
    this.navCtrl.push(TabsPage)
  }

  nothing() {
    
  }

}
