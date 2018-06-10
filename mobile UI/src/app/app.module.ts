import { BrowserModule } from '@angular/platform-browser';
import { ErrorHandler, NgModule } from '@angular/core';
import { IonicApp, IonicErrorHandler, IonicModule } from 'ionic-angular';
import { SplashScreen } from '@ionic-native/splash-screen';
import { StatusBar } from '@ionic-native/status-bar';

import { MyApp } from './app.component';
import { HomePage } from '../pages/home/home';
import { RegisterPage } from '../pages/register/register';
import { MainMenuPage } from '../pages/main-menu/main-menu';
import { HouseholdPage } from '../pages/household/household';
import { DealerPage } from '../pages/dealer/dealer';
import { TabsPage } from '../pages/tabs/tabs';
import { AngularFireModule } from 'angularfire2';
import { AngularFireAuthModule } from 'angularfire2/auth';

const firebaseAuth = {
    apiKey: "AIzaSyCXom-l-MtPmx4bM4VfWbtRFhFKwJYCeJ0",
    authDomain: "test-project-2abe1.firebaseapp.com",
    databaseURL: "https://test-project-2abe1.firebaseio.com",
    projectId: "test-project-2abe1",
    storageBucket: "test-project-2abe1.appspot.com",
    messagingSenderId: "716507429769"
  };


@NgModule({
  declarations: [
    MyApp,
    HomePage,
    RegisterPage,
    MainMenuPage,
    DealerPage,
    HouseholdPage,
    TabsPage
  ],
  imports: [
    BrowserModule,
    IonicModule.forRoot(MyApp),
    AngularFireModule.initializeApp(firebaseAuth),
    AngularFireAuthModule
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    HomePage,
    RegisterPage,
    MainMenuPage,
    HouseholdPage,
    DealerPage,
    TabsPage
  ],
  providers: [
    StatusBar,
    SplashScreen,
    {provide: ErrorHandler, useClass: IonicErrorHandler}
  ]
})
export class AppModule {}
