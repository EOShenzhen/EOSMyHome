import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { MainMenuPage } from '../main-menu/main-menu'
import { HouseholdPage } from '../household/household'

/**
 * Generated class for the TabsPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@IonicPage()
@Component({
  selector: 'page-tabs',
  templateUrl: 'tabs.html',
})
export class TabsPage {
  mainMenuPage = MainMenuPage;
  householdPage = HouseholdPage;

  constructor(public navCtrl: NavController, public navParams: NavParams) {
  }

}
